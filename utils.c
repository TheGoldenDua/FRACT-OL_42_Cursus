 #include "fractol.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (i < n - 1 && str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

double ft_atod(char *str)
{
    double res;
	int signe;
    double j;

    res = 0;
	signe = 1;
	while(*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if(*str == '+' || *str == '-')
	{
		if(*str++ == '-')
			signe = -signe;
	}
	while(*str && *str >= '0' && *str <= '9')
        res = (res * 10) + (*str++ - '0');
	if(*str == '.')
		str++;
    j = 10;
	while(*str && *str >= '0' && *str <= '9')
    {
        res = res + (*str++ - '0') / j;
        j *= 10;
    }
	return (res * signe);
}
