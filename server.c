/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:23:43 by hmohamed          #+#    #+#             */
/*   Updated: 2022/12/13 12:19:42 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>


void	handler(int signal)
{
	static int	bit;
	static char	a;

	if (signal == SIGUSR1)
	{
		a |= (0x01 << bit);
	}
	bit++;
	//  printf("bit = %d", bit);
	if (bit == 8)
	{
		write(1, &a, 1);
		bit = 0;
		a = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	printf("pid :  %d\n", getpid());
	while (ac == 1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
