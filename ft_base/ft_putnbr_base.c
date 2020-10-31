// fonctionne pas mdr

#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     ft_strlen(char *str)
{
    int i;
    while (str[i])
    {
        i++;
    }
    return (i);
}

int     ft_check_base(char *base)
{
    int i;
    int j;

    if (ft_strlen(base) < 2)
        return (0);
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+' || base[i] > 126 || base [i] < 32 )
        j = i + 1;
        while (base[j])
        {
            if (base[j] == base[i])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
    long nbr_l;
    char nbr_c[32];
    int base_divider;
    int i;

    if (!(ft_check_base(base)))
        return ;
    base_divider = ft_strlen(base);
    if (nbr < 0)
    {
        nbr_l = nbr;
        nbr_l = -nbr_l;
        ft_putchar('-');
    }
    else
        nbr_l = nbr;
    i = 0;
    while (nbr_l > 0)
    {
        nbr_c[i] = base[nbr_l % base_divider];
        nbr_l /= base_divider;
        i++;
    }
        while (--i >= 0)
            ft_putchar(nbr_c[i]);
}

int main()
{
    ft_putnbr_base(145778, "LUCAS");
    return (0);
}       
