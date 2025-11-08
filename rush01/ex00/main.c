/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamaj <mdamaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:06:11 by mdamaj            #+#    #+#             */
/*   Updated: 2025/07/27 18:16:46 by mdamaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		parse_clues(char *input, int clues[16]);
int		solve(int grid[4][4], int clues[16], int row, int col);
void	print_grid(int grid[4][4]);
void	ft_putstr(char *str);

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	init_grid(grid);
	if (argc != 2 || !parse_clues(argv[1], clues))
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (!solve(grid, clues, 0, 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid);
	return (0);
}
