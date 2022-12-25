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
