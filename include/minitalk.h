/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:36:27 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/26 02:56:35 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "unistd.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_signal_state
{
	volatile unsigned char	current_byte;
	volatile int			bit_count;
}	t_signal_state;

void	send_bit(int pid, int bit);
void	signal_handler(int sig);

#endif
