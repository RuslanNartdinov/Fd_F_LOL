/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruslannartdinov <ruslannartdinov@student.4 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:32:18 by rnartdin          #+#    #+#             */
/*   Updated: 2024/04/29 11:29:12 by ruslannartdinov  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	counter;
	int	number;
	int	minus;

	counter = 0;
	number = 0;
	minus = 1;
	while ((str[counter] >= 9 && str[counter] <= 13) || (str[counter] == 32))
		counter++;
	if (str[counter] == '-' || str[counter] == '+')
	{
		if (str[counter] == '-')
			minus *= -1;
		counter++;
	}
	while ((str[counter] >= 48) && (str[counter] <= 57))
	{
		number = number + str[counter] - 48;
		if ((str[counter + 1] >= 48) && (str[counter + 1] <= 57))
			number *= 10;
		counter++;
	}
	number = number * minus;
	return (number);
}
// int main()
// {
// 	char str[] = "+47";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return(0);
// }
