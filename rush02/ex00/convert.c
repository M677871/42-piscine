/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:49:20 by pabdalla          #+#    #+#             */
/*   Updated: 2025/08/04 22:31:27 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		split_grp(char *num, char ***G);
//int		dict_lookup(char **K, char **V, size_t N, char *s);
char	*dict_lookup(char **K, char **V, size_t N, char *s);
void	print_w(char *w);

static int	conv_grp(char *g, char **K, char **V, size_t N)
{
	char	buf[3];
	int		len;

	len = 0;
	while (g[len] != '\0')
		len++;
	if (len == 3 && g[0] != '0')
	{
		buf[0] = g[0];
		buf[1] = '\0';
		if (dict_lookup(K, V, N, buf) == 0)
			return (-1);
		print_w(dict_lookup(K, V, N, buf));
		print_w("100");
	}
	return (0);
}

int	convert_num(char *num, char **K, char **V, size_t N)
{
	char	**gg;
	int		g;
	int		i;
	char	*sc[5];
	int		ret;

	sc[0] = "";
	sc[1] = "thousand";
	sc[2] = "million";
	sc[3] = "billion";
	sc[4] = "trillion";
	g = split_grp(num, &gg);
	if (g < 0)
		return (-1);
	i = 0;
	while (i < g)
	{
		ret = conv_grp(gg[i], K, V, N);
		free(gg[i]);
		if (ret < 0)
			return (free(gg), -1);
		if (*sc[g - 1 - i] != '\0')
			print_w(sc[g - 1 - i]);
		i++;
	}
	free(gg);
	write(1, "\n", 1);
	return (0);
}
