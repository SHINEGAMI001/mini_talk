/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlachhab <hlachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:35:29 by hlachhab          #+#    #+#             */
/*   Updated: 2024/09/21 01:38:40 by hlachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void	signal_handler(int signal, siginfo_t *sa, void *context)
{
	static int	i;
	static char	c;
	static int	pid;

	context = NULL;
	if (pid != sa->si_pid)
	{
		if (pid != 0)
			ft_putchar('\n');
		i = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		c = c | (1 << i);
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		c = 0;
		i = 0;
	}
	pid = sa->si_pid;
}

int	main(int ac, char **av)
{
	struct sigaction	msg;
	int					pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		write(1, "MY PID :", 9);
		ft_putnbr(pid);
		write(1, "\n", 1);
		msg.sa_sigaction = &signal_handler;
		sigaction(SIGUSR1, &msg, NULL);
		sigaction(SIGUSR2, &msg, NULL);
		while (1)
			pause();
	}
	return (0);
}
