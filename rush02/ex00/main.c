/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:00:30 by pabdalla          #+#    #+#             */
/*   Updated: 2025/08/03 23:25:03 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		is_valid(char *s);
int		parse_dict(char *file, char ***K, char ***V, size_t *N);
void	free_dict(char **K, char **V, size_t N);
int		convert_num(char *num, char **K, char **V, size_t N);
void	err_num(void);
void	err_dict(void);

int main(int ac, char **av)
{
	char	**K;
	char	**V;
	char	*file;
	char	*num;
	size_t	N;
	int		ret;

	if (ac == 2)
	{
		file = "numbers.dict";
		num = av[1];
	}
	else if (ac == 3)
	{
		file = av[1];
		num = av[2];
	}
	else
	{
		err_num();
		return (1);
	}
	if (!is_valid(num))
	{
		err_num();
		return (1);
	}
	ret = parse_dict(file, &K, &V, &N);
	if (ret < 0)
	{
		err_dict();
		return (1);
	}
	ret = convert_num(num, K, V, N);
	if (ret < 0)
	{
		free_dict(K, V, N);
		err_dict();
		return (1);
	}
	free_dict(K, V, N);
	return (0);
}
