/*
** my_remp_map.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon Feb 20 19:21:44 2017 Florian Testu
** Last update Sun Feb 26 17:24:40 2017 Florian Testu
*/

#include "my.h"

char    **midle_stick(char **tab, t_match *compt)
{
  int   i;
  int   j;

  i = -1;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
	{
	  if (j == compt->lines)
	    tab[i][j] = '|';
	}
    }
  return (tab);
}

char    **error_stick(char **tab, int i, int j)
{
  if (j > 0)
    {
      if (tab[i][j] == '|' && tab[i][j - 1] == '*' && tab[i][j + 1] == '*')
	tab[i][j] = '*';
      if (tab[i][j] == '|' && tab[i - 1][j] == '|')
	{
	  tab[i][j - 1] = '|';
	  tab[i][j + 1] = '|';
	}
    }
  return (tab);
}

char    **my_put_stick(char **tab, t_match *compt)
{
  int   i;
  int   j;

  tab =  midle_stick(tab, compt);
  while (tab[compt->lines][1] != '|')
    {
      i = -1;
      while (tab[++i] != NULL)
	{
	  j = -1;
	  while (tab[i][++j] != '\0')
	    tab = error_stick(tab, i, j);
	}
    }
  return (tab);
}

char    **my_turn_map(int lin, int col)
{
  int   i;
  int   j;
  char  **tab;

  i = -1;
  if ((tab = malloc(sizeof(char*) * (lin + 2))) == NULL)
    return (NULL);
  while (++i != lin)
    {
      if ((tab[i] = malloc(sizeof(char) * (col + 2))) == NULL)
	return (NULL);
      j = -1;
      while (++j != col)
	{
	  if (i == 0 || i == lin - 1 || j == 0 || j == col -1)
	    tab[i][j] = '*';
	  else
	    tab[i][j] = ' ';
	}
      tab[i][j] = '\n';
      tab[i][j + 1] = '\0';
    }
  tab[i] = NULL;
  return (tab);
}

int		my_map(int argc, char **argv)
{
  t_match	*compt;
  int		col;
  int		lin;
  char		**tab;
  int		i;

  argc = argc;
  argv = argv;
  if ((compt = malloc(sizeof(t_match))) == NULL)
    return (NULL);
  compt->lines = my_getnbr(argv[1]);
  compt->number = my_getnbr(argv[2]);
  col = compt->lines * 2 + 1;
  lin = compt->lines + 2;
  if ((tab = my_turn_map(lin, col)) == NULL)
    return (84);
  tab = my_put_stick(tab, compt);
  i = my_game(tab, compt);
  if (i == 1)
    return (1);
  else if (i == 2)
    return (2);
  else
    return (0);
}
