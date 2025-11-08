/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miissa <miissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:43:23 by pabdalla          #+#    #+#             */
/*   Updated: 2025/08/04 22:23:53 by miissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *s);
int		ft_strcmp(char *a, char *b);
char	*ft_strdup(char *s);
void	err_num(void);
void	err_dict(void);

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *a, char *b)
{
	size_t	i;

	i = 0;
	while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i])
		i++;
	return ((unsigned char)a[i] - (unsigned char)b[i]);
}

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*p;
	size_t	i;

	len = ft_strlen(s);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		p[i] = s[i];
		i++;
	}
	return (p);
}

void	err_num(void)
{
	write(1, "Error\n", 6);
}

void	err_dict(void)
{
	write(1, "Dict Error\n", 11);
}
void	free_dict(char **k,char **v,size_t n)
{
	size_t i = 0;
	while(i < n)
	{
		free(k[i]);
		free(v[i]);
		i++;
	}
	free(k);
	free(v);
}
