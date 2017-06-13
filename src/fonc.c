/*
** fonc.c for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Mon Feb 20 13:50:53 2017 Florian Testu
** Last update Mon Feb 27 13:12:24 2017 Florian Testu
*/

#include "my.h"

void	my_putchar(char z)
{
  write(1, &z, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    my_putchar(str[i]);
}

void	my_putnbr(int nb)
{
  int   div;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  div = 1;
  while (nb / div > 9)
    div = div * 10;
  while (div != 0)
    {
      my_putchar(nb / div + 48);
      nb = nb % div;
      div = div / 10;
    }
}

int     my_getnbr(char *str)
{
  int i;
  int odg;
  int nb;

  odg = 1;
  nb = 0;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	odg = odg * -1;
      i = i + 1;
    }
  while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + str[i] - 48;
      if (nb > 214748363 || nb < -214748363)
	return (0);
      i = i + 1;
    }
  nb = nb * odg;
  return (nb);
}

void    print_map(char **tab)
{
  int   i;

  i = -1;
  while (tab[++i] != NULL)
    my_putstr(tab[i]);
}
