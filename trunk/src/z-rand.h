/* File: z-rand.h */

/*
 * Copyright (c) 2007 Ben Harrison, and others
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, version 2.  Parts may also be available under the
 * terms of the Moria license.  For more details, see "/docs/copying.txt".
 */

#ifndef INCLUDED_Z_RAND_H
#define INCLUDED_Z_RAND_H

#include "h-basic.h"



/**** Available constants ****/


/*
 * The "degree" of the "complex" Random Number Generator.
 * This value is hard-coded at 63 for a wide variety of reasons.
 */
#define RAND_DEG 63




/**** Available macros ****/


/*
 * Generates a random long integer X where O<=X<M.
 * The integer X falls along a uniform distribution.
 * For example, if M is 100, you get "percentile dice"
 */
#define rand_int(M) \
	(Rand_div(M))


/*
 * Generates a random long integer X where 1<=X<=M.
 */
#define randint(M) \
	(rand_int(M) + 1)


/*
 * Generates a random long integer X where A<=X<=B
 * The integer X falls along a uniform distribution.
 * Note: rand_range(0,N-1) == rand_int(N)
 */
#define rand_range(A,B) \
	((A) + (rand_int(1+(B)-(A))))

/*
 * Generate a random long integer X where A-D<=X<=A+D
 * The integer X falls along a uniform distribution.
 * Note: rand_spread(A,D) == rand_range(A-D,A+D)
 */
#define rand_spread(A,D) \
	((A) + (rand_int(1+(D)+(D))) - (D))


/*
 * An alternative method of calling "rand_int()".
 * From Zangband.
 */
#define one_in_(X) \
	(rand_int(X) == 0)

/**** Available Variables ****/


extern bool Rand_quick;
extern u32b Rand_value;
extern u16b Rand_place;
extern u32b Rand_state[RAND_DEG];


/**** Available Functions ****/


extern void Rand_state_init(u32b seed);
extern s32b Rand_div(s32b m);
extern s16b Rand_normal(s32b mean, s16b stand);
extern s32b Rand_simple(s32b m);
extern s32b div_round(s32b n, s32b d);


#endif /* INCLUDED_Z_RAND_H */