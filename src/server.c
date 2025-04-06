/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:36:33 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/06 11:38:12 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	current_byte = 0;
	static int	bit_count = 0;
	static int	client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		write(1, "\n", 1);
		client_pid = info->si_pid;
		bit_count = 0;
		current_byte = 0;
	}
	if (sig == SIGUSR1)
		current_byte = current_byte << 1;
	else if (sig == SIGUSR2)
		current_byte = (current_byte << 1) | 1;
	bit_count++;
	if (bit_count >= 8)
	{
		write(1, &current_byte, 1);
		current_byte = 0;
		bit_count = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		ft_printf("Error: Failed to send acknowledgment to %d\n", client_pid);
}

void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL)
		== -1)
	{
		ft_printf("Error: Failed to set up signal handlers\n");
		exit(1);
	}
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d", pid);
}

int	main(void)
{
	print_pid();
	setup_signals();
	while (1)
		pause();
	return (0);
}
