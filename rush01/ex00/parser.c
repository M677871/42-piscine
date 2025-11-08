/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdamaj <mdamaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 11:05:31 by mdamaj            #+#    #+#             */
/*   Updated: 2025/07/27 17:45:03 by mdamaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_clues(char *input, int clues[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			if (count >= 16)
				return (0);
			clues[count++] = input[i] - '0';
		}
		else if (input[i] != ' ')
			return (0);
		i++;
	}
	return (count == 16);
}
