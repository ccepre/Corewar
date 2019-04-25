/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globales.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccepre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:58:57 by ccepre            #+#    #+#             */
/*   Updated: 2019/04/25 13:35:04 by ccepre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int g_automate[27][13] =
{
	{0,1,6,7,8,14,16,18,20,24,26,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,-1,-1},
	{3,-1,-1,-1,-1,-1,-1,-1,2,-1,-1,4,-1},
	{3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,4,-1},
	{4,4,4,4,4,4,4,4,4,4,4,5,4},
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
	{-1,-1,-1,-1,-1,9,11,12,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,10,10,10,-1,-1,-1},
	{13,-1,13,13,-1,-1,-1,10,10,10,13,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,12,-1,-1,-1,-1,-1},
	{13,-1,13,13,-1,-1,-1,12,-1,-1,13,-1,-1},
	{-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3},
	{-1,-1,-1,-1,-1,-1,-1,15,15,15,-1,-1,-1},
	{19,-1,19,19,-1,-1,-1,15,15,15,19,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,17,-1,-1,-1,-1,-1},
	{19,-1,19,19,-1,-1,-1,17,-1,-1,19,-1,-1},
	{19,-1,19,19,-1,-1,-1,18,21,21,19,-1,-1},
	{-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3},
	{23,-1,23,23,-1,22,-1,21,20,20,23,-1,-1},
	{-1,-1,-1,-1,-1,22,-1,21,21,21,-1,-1,-1},
	{-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2,-2},
	{-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3},
	{25,-1,25,25,-1,-1,-1,24,-1,-1,25,-1,-1},
	{-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3,-3},
	{26,26,6,26,26,26,26,26,26,26,26,26,26}
};

char	*g_index_col[12] = 
{
	" \t",
	".",
	"\n",
	",",
	"%",
	":",
	"-",
	"0123456789",
	"abcdefghijklmnopqstuvwxyz_",
	"r",
	"#;",
	"\"",
};

char	*(g_instructions[16]) = 
{
	"live",
	"ld",
	"st",
	"add",
	"sub",
	"end",
	"or",
	"xor",
	"zjmp",
	"ldi",
	"sti",
	"fork",
	"lld",
	"lldi",
	"lfork",
	"aff",
};
