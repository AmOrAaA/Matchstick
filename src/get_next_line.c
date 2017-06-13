/*
** get_next_line.c for get_next_line.c in /home/AmOrAA/Delivery/GetNextLine/CPE_2016_getnextline
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Thu Jan 26 11:21:20 2017 Florian Testu
** Last update Sat Apr  8 21:57:48 2017 Florian Testu
*/

#include "my.h"
#include "get_next_line.h"

int     my_strlen(char *a)
{
  int	b;

  b = 0;
  if (a == NULL)
    return (0);
  while  (a[b] != '\0')
    b = b + 1;
  return (b);
}

char    *my_strcat(char *dest, char *src)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest && dest[i] != '\0')
    {
      new[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    new[i++] = src[j++];
  new[i] = '\0';
  return (new);
}

char    *my_strdup(char *str)
{
  int   a;
  char	*tmp;

  a = 0;
  if (str == NULL)
    return (NULL);
  if ((tmp = malloc(my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[a] != '\0')
    {
      tmp[a] = str[a];
      a = a + 1;
    }
  tmp[a] = '\0';
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE + 1];
  int		res;
  int		i;
  int           j;
  static char	*str;
  char		*ret;

  i = 0;
  res = read(fd, buff, READ_SIZE);
  if (res <= 0 && !str)
    return (NULL);
  buff[res] = '\0';
  str = my_strcat(str, buff);
  j = i;
  while (str[i] != '\0' && str[i] != '\n')
    i = i + 1;
  if (str[i] == '\0')
    {
      ret = my_strdup(str);
      str = NULL;
      return (ret);
    }
  ret = my_save(str, i, j);
  str = &str[i + 1];
  i++;
  return (ret);
}

char	*my_save(char *str, int i, int j)
{
  char	*ret;

  str[i] = '\0';
  ret = my_strdup(&str[j]);
  return (ret);
}
