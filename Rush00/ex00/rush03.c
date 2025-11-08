/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 08:42:16 by miissa            #+#    #+#             */
/*   Updated: 2025/07/19 09:28:37 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_line(int width, char start, char fill, char end)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (j == 0)
			ft_putchar(start);
		else if (j == width - 1)
			ft_putchar(end);
		else
			ft_putchar(fill);
		j++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	count;

	count = 0;
	if (x > 0 && y > 0)
	{
		while (count < y)
		{
			if (count == 0 || count == y - 1)
				draw_line(x, 'A', 'B', 'C');
			else
				draw_line(x, 'B', ' ', 'B');
			count++;
		}
	}
}
