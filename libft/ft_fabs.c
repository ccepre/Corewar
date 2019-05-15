/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fabs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malluin <malluin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:06:26 by malluin           #+#    #+#             */
/*   Updated: 2018/12/18 19:45:26 by malluin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_fabs(float x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}