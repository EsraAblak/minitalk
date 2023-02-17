/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:50:15 by eablak            #+#    #+#             */
/*   Updated: 2022/11/18 11:51:07 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	sayi;

	i = 0;
	neg = 1;
	sayi = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = sayi * 10 + (str[i] - 48);
		if (sayi * neg < -2147483648)
			return (0);
		else if (sayi * neg > 2147483647)
			return (-1);
		i++;
	}
	return (sayi * neg);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	j;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (0);
	while (av[2][i])
	{
		j = 7;
		while (j >= 0)
		{
			if ((av[2][i] >> j) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j--;
			usleep(100);
		}
		i++;
	}
}
