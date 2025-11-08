/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamaj <mdamaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:05:48 by mdamaj            #+#    #+#             */
/*   Updated: 2025/07/27 17:44:12 by mdamaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_safe(int grid[4][4], int row, int col, int num);
int	check_all_clues(int grid[4][4], int clues[16]);

int	solve(int grid[4][4], int clues[16], int row, int col)
{
	int	num;

	num = 1;
	if (row == 4)
		return (check_all_clues(grid, clues));
	if (col == 4)
		return (solve(grid, clues, row + 1, 0));
	while (num <= 4)
	{
		if (is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
