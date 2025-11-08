/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkRC.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamaj <mdamaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:18:21 by mdamaj            #+#    #+#             */
/*   Updated: 2025/07/27 19:21:30 by mdamaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line);

int	check_row(int grid[4][4], int clues[16], int row)
{
	int	i;
	int	left[4];
	int	right[4];

	i = 0;
	while (i < 4)
	{
		left[i] = grid[row][i];
		right[i] = grid[row][3 - i];
		i++;
	}
	if (count_visible(left) != clues[8 + row])
		return (0);
	if (count_visible(right) != clues[12 + row])
		return (0);
	return (1);
}

int	check_rows(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_row(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}

int	check_column(int grid[4][4], int clues[16], int col)
{
	int	i;
	int	up[4];
	int	down[4];

	i = 0;
	while (i < 4)
	{
		up[i] = grid[i][col];
		down[i] = grid[3 - i][col];
		i++;
	}
	if (count_visible(up) != clues[col])
		return (0);
	if (count_visible(down) != clues[4 + col])
		return (0);
	return (1);
}

int	check_columns(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_column(grid, clues, i))
			return (0);
		i++;
	}
	return (1);
}
