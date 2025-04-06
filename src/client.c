/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <mel-hajj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 02:36:39 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/26 03:30:14 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_char(int pid, unsigned char c)
{
	int		i;
	int		bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		send_bit(pid, bit);
		i--;
	}
}

void	send_string(int pid, char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, '\0');
	send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	int		pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client <pid> <string>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	send_string(pid, argv[2]);
	return (0);
}
