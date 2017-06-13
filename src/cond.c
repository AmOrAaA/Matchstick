/*
** cond.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Fri Feb 24 13:53:04 2017 Florian Testu
** Last update Sun Feb 26 13:04:21 2017 Florian Testu
*/

#include "my.h"

char	**cond_1_2(char **tab, t_match *compt)
{
  int	i;
  int	col;
  int	x;

  i = -1;
  while (tab[++i] != NULL)
    {
      x = 1;
      col = compt->lines * 2;
      while (--col != 0)
	{
	  if (tab[i][col] == '|')
	    {
	      tab[i][col] = ' ';
	      x = x - 1;
	    }
	  if (x == 0)
	    {
	      compt->ia_lines = i;
	      compt->ia_match = 1;
	      return (tab);
	    }
	}
    }
  return (0);
}

char    **cond_2(char **tab, int col, t_match *compt)
{
  int   i;
  int   x;

  i = -1;
  while (tab[++i] != NULL)
    {
      x = 0;
      col = compt->lines * 2 + 1;
      while (col != 0)
	{
	  if (tab[i][col] == '|')
	    x = x + 1;
	  col = col - 1;
	}
      if (x >= 2)
	{
	  tab = cond_2_1(tab, i, compt);
	  return (tab);
	}
    }
  return (0);
}

char    **cond_2_1(char **tab, int i, t_match *compt)
{
  int   x;
  int   col;

  x = 2;
  col = compt->lines * 2 + 1;
  while (col != 0)
    {
      if (tab[i][col] == '|')
	{
	  tab[i][col] = ' ';
	  x = x - 1;
	}
      if (x == 0)
	{
	  compt->ia_lines = i;
	  compt->ia_match = 2;
	  return (tab);
	}
      col = col - 1;
    }
  return (0);
}

char    **cond_3(char **tab, int col, t_match *compt)
{
  int   i;
  int   x;

  i = -1;
  while (tab[++i] != NULL)
    {
      x = 1;
      col = compt->lines * 2 + 1;
      while (col != 0)
	{
	  if (tab[i][col] == '|')
	    {
	      tab[i][col] = ' ';
	      x = x - 1;
	    }
	  if (x == 0)
	    {
	      compt->ia_lines = i;
	      compt->ia_match = 1;
	      return (tab);
	    }
	  col = col - 1;
	}
    }
  return (0);
}
