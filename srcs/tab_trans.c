/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_trans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtian <jtian@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 17:47:56 by phtruong          #+#    #+#             */
/*   Updated: 2022/02/23 19:37:50 by jtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*shift_tet(int *tab, int x, int y)
{
	int i;
	int size;

	size = 4;
	i = 0;
	while (size--)
	{
		tab[i] = tab[i] + x;
		tab[i+1] = tab[i+1] + y;
		i += 2;
	}
	return (tab);
}

int	valid_piece(int *tet)
{
	if (tabcmp(tet, I_PIECE, sizeof(tet)) ||
		tabcmp(tet, IH_PIECE, sizeof(tet)) ||
		tabcmp(tet, O_PIECE, sizeof(tet)) ||
		tabcmp(tet, L_PIECE, sizeof(tet)) ||
		tabcmp(tet, LR_PIECE, sizeof(tet)) ||
		tabcmp(tet, LD_PIECE, sizeof(tet)) ||
		tabcmp(tet, LL_PIECE, sizeof(tet)) ||
		tabcmp(tet, J_PIECE, sizeof(tet)) ||
		tabcmp(tet, JR_PIECE, sizeof(tet)) ||
		tabcmp(tet, JD_PIECE, sizeof(tet)) ||
		tabcmp(tet, JL_PIECE, sizeof(tet)) ||
		tabcmp(tet, T_PIECE, sizeof(tet)) ||
		tabcmp(tet, TR_PIECE, sizeof(tet)) ||
		tabcmp(tet, TD_PIECE, sizeof(tet)) ||
		tabcmp(tet, TL_PIECE, sizeof(tet)) ||
		tabcmp(tet, S_PIECE, sizeof(tet)) ||
		tabcmp(tet, SR_PIECE, sizeof(tet)) ||
		tabcmp(tet, Z_PIECE, sizeof(tet)) ||
		tabcmp(tet, ZR_PIECE, sizeof(tet)))
		return (1);
	return(0);
}
