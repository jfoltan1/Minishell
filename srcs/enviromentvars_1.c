/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviromentvars_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:07:17 by hstein            #+#    #+#             */
/*   Updated: 2024/02/15 14:07:17 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**arrdup(char **enviroment)
{
	int			rows;
	char		**dup;

	rows = 0;
	while (enviroment[rows])
		rows++;
	dup = ft_calloc(rows + 2, sizeof(char **));
	if (!dup)
		return (NULL);
	rows = 0;
	while (enviroment[rows] != NULL)
	{
		dup[rows] = ft_strdup(enviroment[rows]);
		if (dup[rows] == NULL)
			return (NULL);
		rows++;
	}
	dup[rows] = NULL;
	return (dup);
}

int	emptyvar(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	printenv(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!emptyvar(env[i]))
		{
			ft_putstr_fd(env[i], 1);
			printf("\n");
		}
		i++;
	}
}

void	purge_arr(char *cmds, char ***env)
{
	char	**temp;
	int		a;

	a = 0;
	temp = ft_split(cmds, '=');
	delete_env_var(temp[0], env);
	while (temp[a])
	{
		free(temp[a]);
		a++;
	}
	free(temp);
}
