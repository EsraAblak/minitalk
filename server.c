/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: eablak <marvin@42.fr>                      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/18 11:51:31 by eablak            #+#    #+#             */
/*   Updated: 2022/11/18 11:52:18 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sig(int sig)
{
	static int	i;
	static int	c;

	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
		pause();
}
