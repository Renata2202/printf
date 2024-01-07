/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:53:01 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/19 18:51:39 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
//# include "libft/libft.h"

# define HEXL "0123456789abcdef"
# define HEXU "0123456789ABCDEF"

int	ft_printf(const char *format, ...);

#endif
