/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabdalla <pabdalla@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:30:30 by pabdalla          #+#    #+#             */
/*   Updated: 2025/08/03 23:08:30 by pabdalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
char	*ft_strdup(char *s);

static	int	line_to_kv(char *buf, char **k, char **v)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != ':')
		i++;
	if (buf[i] != ':')
		return (0);
	buf[i] = '\0';
	*k = ft_strdup(buf);
	*v = ft_strdup(buf + i + 1);
	if (*k == NULL || *v == NULL)
		return (-1);
	return (1);
}

int	parse_dict(char *file, char ***K, char ***V, size_t *N)
{
	int		fd;
	char	*buf;
	ssize_t	r;
	char	*keys_arr[512];
	char	*vals_arr[512];
	size_t	cnt;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	buf = malloc(8192 + 1);
	if (buf == NULL)
		return (-1);
	r = read(fd, buf, 8192);
	close(fd);
	if (r <= 0)
		return (-1);
	buf[r] = '\0';
	cnt = 0;
	line = buf;
	while (cnt < 512 && line != NULL)
	{
		tmp = line;
		while (*tmp != '\0' && *tmp != '\n')
			tmp++;
		if (*tmp == '\n')
			*tmp++ = '\0';
		if (line_to_kv(line, &keys_arr[cnt], &vals_arr[cnt]) < 0)
			return (-1);
		if (keys_arr[cnt][0] != '\0')
			cnt++;
		line = tmp;
	}
	*K = malloc(cnt * sizeof(*keys_arr));
	*V = malloc(cnt * sizeof(*vals_arr));
	*N = cnt;
	while (cnt > 0)
	{
		cnt--;
		(*K)[cnt] = keys_arr[cnt];
		(*V)[cnt] = vals_arr[cnt];
	}
	return (0);
}

char	*dict_lookup(char **K, char **V, size_t N, char *s)
{
	while (N > 0)
	{
		N--;
		if (ft_strcmp(K[N], s) == 0)
			return (V[N]);
	}
	return (0);
}
