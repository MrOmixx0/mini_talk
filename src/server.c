/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:36:33 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/26 03:05:32 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Single global struct for signal state
static t_signal_state	g_state = {0, 0};

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		g_state.current_byte = g_state.current_byte << 1;
	else if (sig == SIGUSR2)
		g_state.current_byte = (g_state.current_byte << 1) | 1;
	g_state.bit_count++;
	if (g_state.bit_count == 8)
	{
		write(1, (char *)&g_state.current_byte, 1);
		g_state.current_byte = 0;
		g_state.bit_count = 0;
	}
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
}

int	main(void)
{
	print_pid();
	setup_signals();
	while (1)
		pause();
	return (0);
}
