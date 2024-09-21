/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:34:55 by hlachhab          #+#    #+#             */
/*   Updated: 2024/09/21 01:21:10 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	count;
	int	sign;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i] <= 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = count * 10 + (str[i] - '0');
		i++;
	}
	return (count * sign);
}

void	send_bits(int pid, char c)
{
	int	shift;

	shift = 0;
	while (shift <= 7)
	{
		if (c & (1 << shift))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		shift++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
		write(1, "- wrong arguments !\n", 20);
	return (0);
}
