/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamaj <mdamaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:04:43 by mdamaj            #+#    #+#             */
/*   Updated: 2025/07/27 19:18:54 by mdamaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_rows(int grid[4][4], int clues[16]);
int	check_columns(int grid[4][4], int clues[16]);

int	count_visible(int *line)
{
	int	max;
	int	count;
	int	i;

	i = 0;
	count = 0;
	max = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

int	check_all_clues(int grid[4][4], int clues[16])
{
	if (!check_rows(grid, clues))
		return (0);
	if (!check_columns(grid, clues))
		return (0);
	return (1);
}
