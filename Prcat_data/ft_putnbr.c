#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void put_nbr(int i)
{
    char *str = "0123456789";
    if(i < 0)
    {
        write(1, "-", 1);
        i *=-1;
    }
    if(i > 9)
        put_nbr(i / 10);
    write(1, &str[i % 10], 1);
    
}

void ft_pustr(char *str)
{
    while(*str)
        write(1, str++, 1);
}

int ft_atoi(char *str)
{   
    int    result = 0;
    int    sign = 1;
    int i = 0;
    // skipping the white spaces and positive and negative characters
    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
   while(str[i] == '+' || str[i] == '-')
   {
    if(str[i] == '-')
        sign = -1;
     i++;
   }
       
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + str[i] - 48;
        i++;
    }
    return result * sign;
}

int main(void)
{
    // int i = ft_atoi(" ---+--+1234ab567");
    // int j = atoi(" ---+--+1234ab567");
    // printf("i %d\nj %d", i, j);
// put_nbr(i);
// put_nbr(j);
ft_pustr("Amone");

}