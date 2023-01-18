/**        DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 *
 * Copyright (C) 2022 Matthias Gatto <uso.cosmo.ray@gmail.com>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *  TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "cuwu.h"

#define IN_BUF_LEN 1024
#define OUT_BUF_LEN IN_BUF_LEN * 2

int main(void)
{
	char in[IN_BUF_LEN];
	char out[OUT_BUF_LEN];
	ssize_t rret;

	while ((rret = read(0, in, IN_BUF_LEN - 1))) {
		in[rret] = 0;
		cuwuify(in, out, OUT_BUF_LEN - rret);
		printf("%s", out);
	}
	fflush(stdout);
}
