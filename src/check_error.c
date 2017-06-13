/*
** check_error.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Wed Feb 22 17:59:58 2017 Florian Testu
** Last update Fri Feb 24 21:27:38 2017 Florian Testu
*/

#include "my.h"

int     check_error_line(t_tr my_tr, int stick, char **tab)
{
  int   i;
  int   j;

  j = -1;
  i = 0;
  while (tab[my_tr.the_line][++j] != '\0')
    {
      if (tab[my_tr.the_line][j] == '|')
	i = i + 1;
    }
  if (i < stick)
    return (84);
  return (0);
}

int    check_error_str(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[0] == '0')
	{
	  my_putstr("Error: you have to remove at least one match\n");
	  free (str);
	  str = NULL;
	  return (84);
	}
      else
	if (str[i] < '0' || str[i] > '9')
	  {
	    my_putstr("Error: invalid input (positive number expected)\n");
	    free (str);
	    str = NULL;
	    return (84);
	  }
    }
  return (0);
}

int    check_error_ptr(char *ptr)
{
  int   i;

  i = -1;
  while (ptr[++i] != '\0')
    {
      if (ptr[0] == '0')
	{
	  my_putstr("Error: you have to remove at least one match\n");
	  free (ptr);
	  ptr = NULL;
	  return (84);
	}
      else
	if (ptr[i] < '0' || ptr[i] > '9')
	  {
	    my_putstr("Error: invalid input (positive number expected)\n");
	    free (ptr);
	    ptr = NULL;
	    return (84);
	  }
    }
  return (0);
}
