/*
** matchstick.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon Feb 20 12:52:37 2017 Florian Testu
** Last update Sun Feb 26 18:47:03 2017 Florian Testu
*/

#include "my.h"

char	**check_str_ptr(char **tab, t_match *compt)
{
  t_tr	my_tr;

  while (1)
    {
      my_putstr("Line: ");
      if ((my_tr.str = get_next_line(0)) == NULL)
	return (0);
      if ((check_error_str(my_tr.str)) == 84)
	continue;
      my_tr.the_line = my_getnbr(my_tr.str);
      if (my_tr.the_line > compt->lines)
	{
	  cond_0(my_tr);
	  continue;
	}
      my_putstr("Matches: ");
      if ((my_tr.ptr = get_next_line(0)) == NULL)
	return (0);
      if ((cond_5(tab, my_tr, compt)) == 1)
	continue;
      else
	break;
    }
  tab = print_player(tab, my_tr, compt);
  return (tab);
}

char	**print_player(char **tab, t_tr my_tr, t_match *compt)
{
  tab = player(tab, my_tr, compt);
  my_putstr("Player removed ");
  my_putstr(my_tr.ptr);
  my_putstr(" match(es) from line ");
  my_putstr(my_tr.str);
  my_putchar('\n');
  return (tab);
}

char	**player(char **tab, t_tr my_tr, t_match *compt)
{
  int	col;
  int	stick;
  int	the_line;
  int	result;

  col = compt->lines * 2 + 1;
  the_line = my_getnbr(my_tr.str);
  stick = my_getnbr(my_tr.ptr);
  result = 0;
  while (col != 0)
    {
      if (result == stick)
	return (tab);
      if (tab[the_line][col] == '|')
	{
	tab[the_line][col] = ' ';
	result = result + 1;
	}
      col = col - 1;
    }
  return (tab);
}
