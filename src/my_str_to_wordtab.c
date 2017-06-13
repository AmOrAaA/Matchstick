/*
** my_str_to_wordtab.c for  in /home/AmOrAA/Delivery/mini_shell/PSU_2016_minishell1
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Thu Jan 19 13:00:36 2017 Florian Testu
** Last update Fri Feb 10 22:28:51 2017 Florian Testu
*/

#include "my.h"

int	my_strlen_at_the_line(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	j = j + 1;
      while (str[i] == '\n')
	i = i + 1;
      if (str[i] != '\0')
	i = i + 1;
    }
  return (j + 1);
}

int	my_len_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    i = i + 1;
  return (i + 1);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	a;

  a = 0;
  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char*) * (my_strlen_at_the_line(str) + 1))) == NULL)
    return (NULL);
  while (str[a] == '\n')
    a++;
  while (str[a] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * my_len_space(&str[a]))) == NULL)
	return (NULL);
      i = -1;
      while (str[a] != '\n' && str[a] != '\0')
	tab[j][++i] = str[a++];
      tab[j++][++i] = '\0';
      while (str[a] == '\n')
	a++;
    }
  tab[j] = NULL;
  return (tab);
}
