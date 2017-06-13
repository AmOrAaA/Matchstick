/*
** main.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Fri Feb 24 21:49:57 2017 Florian Testu
** Last update Sun Feb 26 18:48:00 2017 Florian Testu
*/

#include "my.h"

char    **ia(char **tab, t_match *compt)
{
  int   result;
  int   col;

  result = 0;
  col = 0;
  result = compt_stick(tab, result);
  if ((result - compt->number) <= 1)
    {
      tab = cond_1(tab, compt, result);
      return (tab);
    }
  else if ((result % 2) == 0)
    {
      tab = cond_2(tab, col, compt);
      return (tab);
    }
  else if ((result % 2) == 1 || result == 1)
    {
      tab = cond_3(tab, col, compt);
      return (tab);
    }
  return (0);
}

int     compt_stick(char **tab, int result)
{
  int   i;
  int   j;

  i = -1;
  result = 0;
  while (tab[++i] != NULL)
    {
      j = -1;
      while (tab[i][++j] != '\0')
	{
	  if (tab[i][j] == '|')
	    result = result + 1;
	}
    }
  return (result);
}

int     my_game(char **tab, t_match *compt)
{
  while (1)
    {
      print_map(tab);
      if (check_lose_ia(tab) == 1)
	return (1);
      my_putstr("\nYour turn:\n");
      if ((tab = check_str_ptr(tab, compt)) == NULL)
	return (0);
      if (check_lose_player(tab) == 2)
	return (2);
      print_map(tab);
      my_putstr("\nAI's turn...\n");
      tab = ia(tab, compt);
      my_putstr("AI removed ");
      my_putnbr(compt->ia_match);
      my_putstr(" match(es) from line ");
      my_putnbr(compt->ia_lines);
      my_putchar('\n');
    }
}

int     gest_error(int argc, char **argv)
{
  int   j;
  int   i;
  int   x;

  i = 0;
  x = 0;
  argc = argc;
  while (argv[++i] != NULL)
    {
      if (i == 1 && argv[i][0] <= '0')
	return (84);
      if (argv[i][0] <= '0')
	return (84);
      j = -1;
      while (argv[i][++j] != '\0')
	{
	  if (argv[i][j] < '0' || argv[i][j] > '9')
	    return (84);
	  x = x + 1;
	}
      if (i > 3)
	return (84);
    }
  return (0);
}

int     main(int argc, char **argv)
{
  int	i;

  if (argc != 3)
    return (84);
  if (gest_error(argc, argv) == 84)
    return (84);
  i =  my_map(argc, argv);
  if (i == 1)
    {
      my_putchar('\n');
      return (1);
    }
  else if (i == 2)
    {
      my_putchar('\n');
      return (2);
    }
  else
    {
      my_putchar('\n');
      return (0);
    }
}
