/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_savef.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:35:15 by hstein            #+#    #+#             */
/*   Updated: 2023/02/02 21:35:15 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SAVEF_H
# define FT_SAVEF_H

# include <stdarg.h>
# include "../libft/libft.h"

// ft_savef
char	*ft_savef(const char *formatstr, ...);

// ft_savef_utils_A
char	*ft_strjoinfree(char *s1, char const *s2);
void	ft_putnbrstr(char **ptr_ret_line, int n);
void	ft_putunbrstr(char **ptr_ret_line, unsigned int n);
char	*printtype(char **ptr_ret_line, char type, va_list *args);
char	*ft_strhandler(char *ptr_ret_line, char *va_arg_str);

// ft_savef_utils_B
char	*ft_putcharstr(char **ptr_ret_line, int c);
void	ft_putitoxstr(char **ptr_ret_line, \
			unsigned int decimalnumber, char option);
void	ft_putlltoxstr(char **ptr_ret_line, \
			unsigned long long decimalnumber, char option);
void	ft_getptradress(char **ptr_ret_line, void *ptr_adress);

#endif
