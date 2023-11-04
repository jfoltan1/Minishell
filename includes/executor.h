#ifndef EXECUTOR_H
# define EXECUTOR_H

# define _GNU_SOURCE

# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"
# include "../ft_savef/ft_savef.h"
# include "minishell.h"
# include "parser.h"
# include "executor.h"

void	executor(char *clean_word, char **envp);

#endif