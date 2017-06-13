/*
** cond3.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Fri Feb 24 21:52:32 2017 Florian Testu
** Last update Fri Feb 24 22:28:41 2017 Florian Testu
*/

#include "my.h"

int     cond_5(char **tab, t_tr my_tr, t_match *compt)
{
  int   stick;
  int   x;

  x = 0;
  stick = my_getnbr(my_tr.ptr);
  if ((check_error_ptr(my_tr.ptr)) == 84)
    x = 1;
  else if (stick > compt->number)
    x = cond_1_4(my_tr, compt, x);
  else if ((check_error_line(my_tr, stick, tab)) != 0)
    {
      my_putstr("Error: not enough matches on this line\n");
      x = 1;
    }
  return (x);
}

void    cond_0(t_tr my_tr)
{
  free(my_tr.str);
  my_tr.str = NULL;
  my_putstr("Error: this line is out of range\n");
}

int     cond_1_4(t_tr my_tr,  t_match *compt, int x)
{
  free(my_tr.str);
  free(my_tr.ptr);
  my_tr.str = NULL;
  my_tr.ptr = NULL;
  my_putstr("Error: you cannot remove more than ");
  my_putnbr(compt->number);
  my_putstr(" matches per turn\n");
  x = 1;
  return (x);
}
