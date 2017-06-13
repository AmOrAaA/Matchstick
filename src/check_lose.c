/*
** chek_lose.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Tue Feb 21 18:52:48 2017 Florian Testu
** Last update Sun Feb 26 15:13:26 2017 Florian Testu
*/

#include "my.h"

int     check_lose_player(char **tab)
{
  int   i;
  int   j;
  int   compt;

  i = -1;
  compt = 0;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j])
	{
	  if (tab[i][j] == '|')
	    compt = compt + 1;
	}
    }
  if (compt == 0)
    {
      print_map(tab);
      my_putstr("\nYou lost, too bad...");
      return (2);
    }
  return (0);
}

int     check_lose_ia(char **tab)
{
  int   i;
  int   j;
  int   compt;

  i = -1;
  compt = 0;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j])
	{
	  if (tab[i][j] == '|')
	    compt = compt + 1;
	}
    }
  if (compt == 0)
    {
      my_putstr("\nI lost... snif... but I'll get you next time!!");
      return (1);
    }
  return (0);
}
