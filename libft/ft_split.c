/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmajani <mmajani@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:48:01 by mmajani           #+#    #+#             */
/*   Updated: 2023/02/16 14:07:35 by mmajani          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char sep)
{
	size_t	i;
	size_t	nb_of_words;

	i = 0;
	nb_of_words = 0;
	while (s[i])
	{
		if (s[i] && s[i] != sep && (s[i + 1] == sep || s[i + 1] == '\0'))
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

static void	ft_free_all(char **tab, size_t i)
{
	while ((int)i >= 0)
		free(tab[i--]);
	free(tab);
}

static char	*copy_next_word(char const **str, char sep)
{
	char const	*start;

	while (*(*str) && *(*str) == sep)
		(*str)++;
	start = (*str);
	while (*(*str) && *(*str) != sep)
		(*str)++;
	return (ft_substr(start, 0, (*str) - start));
}

char	**ft_split(char const *s, char c)
{	
	int		i;
	int		word_nb;
	char	**stab;

	word_nb = ft_countwords(s, c);
	if (!s)
		return (NULL);
	stab = ft_calloc(word_nb + 1, sizeof(char *));
	i = 0;
	if (!stab)
		return (NULL);
	while (i < word_nb)
	{
		stab[i] = copy_next_word(&s, c);
		if (!stab[i])
		{
			ft_free_all(stab, i);
			return (NULL);
		}
		i++;
	}
	stab[i] = NULL;
	return (stab);
}
