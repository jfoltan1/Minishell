/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 02:57:58 by hstein            #+#    #+#             */
/*   Updated: 2024/02/19 17:49:45 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static t_data	*init_data(t_data *data, char **envp, int argc)
{
	if (argc != 1)
	{
		printf("Error: Minishell does not accept any arguments,");
		printf("but nice try ;)\n");
		exit(1);
	}
	data = malloc(sizeof(t_data));
	data->envp = arrdup(envp);
	data -> original_fd_in = dup(STDIN_FILENO);
	data -> original_fd_out = dup(STDOUT_FILENO);
	return (data);
}

void	reset(t_data *data)
{
	dup2(data->original_fd_in, 0);
	dup2(data->original_fd_out, 1);
	data->last_exit_status = g_exit_status;
	g_exit_status = 0;
}

void	run_shell(t_data *data, char *input)
{
	assign_interactive_signals();
	data->nodes = init_nodes(input, data);
	if (data->nodes != NULL)
		executor(data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;
	char	*input;

	(void)argv; 
	data = NULL;
	data = init_data(data, envp, argc);
	while (true)
	{
		assign_signals();
		reset(data);
		input = readline("Minishell>>: ");
		if (input == NULL)
			if (rl_end == 0)
				exit(0);
		if (input && input[0] != '\0')
		{
			add_history(input);
			if (valid_input(input))
				run_shell(data, input);
			else
				printf("-minishell: %s: Invalid input\n", input);
			free_and_close_data(data);
		}
	}
}
