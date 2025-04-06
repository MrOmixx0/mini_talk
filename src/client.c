/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:36:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/06 11:19:08 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack_received = 0;

void	wait_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_bit(int server_pid, int bit)
{
	if (bit == 0)
	{
		if (kill(server_pid, SIGUSR1) == -1)
		{
			ft_printf("Error: Failed to send SIGUSR1 to %d\n", server_pid);
			exit(1);
		}
	}
	else
	{
		if (kill(server_pid, SIGUSR2) == -1)
		{
			ft_printf("Error: Failed to send SIGUSR2 to %d\n", server_pid);
			exit(1);
		}
	}
	while (!g_ack_received)
	{
		if (kill(server_pid, 0) == -1)
		{
			ft_printf("Error: Server stopped running\n");
			exit(1);
		}
	}
	g_ack_received = 0;
}

void	send_char(int server_pid, unsigned char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(server_pid, bit);
		i--;
	}
}

void	send_string(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(server_pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	signal(SIGUSR1, wait_ack);
	if (argc != 3)
	{
		ft_printf("Usage: ./client <pid> <string>\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	send_string(server_pid, argv[2]);
	return (0);
}
