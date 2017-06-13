/*
** cond2.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Fri Feb 24 21:38:24 2017 Florian Testu
** Last update Sun Feb 26 15:48:23 2017 Florian Testu
*/

#include "my.h"

char            **cond_1(char **tab, t_match *compt, int result)
{
  t_cond        cond;
  int           col;

  cond.i = -1;
  compt->ia_lines = 0;
  compt->ia_match = 0;
  while (tab[++cond.i] != NULL)
    {
      cond.x = 0;
      col = compt->lines * 2 + 1;
      while (col != 0)
	{
	  if (tab[cond.i][col] == '|')
	    cond.x = cond.x + 1;
	  col = col - 1;
	}
      if ((cond_1_5(&tab, result, compt, cond)) == 84)
	return (tab);
    }
  tab = cond_1_2(tab, compt);
  return (tab);
}

int     cond_1_5(char ***tab, int result, t_match *compt, t_cond cond)
{
  if (result == 1)
    {
      cond_1_0(&tab, compt);
      return (84);
    }
  else if ((result - cond.x) <= 1)
    {
      cond_1_1(&tab, result, cond, compt);
      return (84);
    }
  return (0);
}

int             cond_1_0(char ****tab, t_match *compt)
{
  int   x;
  int   col;
  int   i;

  x = 0;
  i = -1;
  while (tab[0][0][++i] != NULL)
    {
      col = compt->lines * 2 + 1;
      while (col != 0)
	{
	  if (tab[0][0][i][col] == '|')
	    {
	      tab[0][0][i][col] = ' ';
	      x = x + 1;
	    }
	  if (x == 1)
	    {
	      compt->ia_lines = i;
	      compt->ia_match = x;
	      return (84);
	    }
	  col = col - 1;
	}
    }
  return (0);
}

int     cond_1_1(char ****tab, int result, t_cond cond, t_match *compt)
{
  int   x;
  int   col;

  x = 0 + 0 * (col = compt->lines * 2);
  while (--col != 0)
    {
      if (tab[0][0][cond.i][col] == '|')
	{
	  tab[0][0][cond.i][col] = ' ';
	  x = x + 1;
	  if (result == 1)
	    {
	      compt->ia_lines = cond.i;
	      compt->ia_match = cond.x;
	      return (84);
	    }
	}
      if ((result - x) == 1)
	{
	  compt->ia_lines = cond.i;
	  compt->ia_match = cond.x;
	  return (84);
	}
    }
  return (0);
}
