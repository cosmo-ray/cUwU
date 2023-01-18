
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

#ifndef CUWU_
#define CUWU_

#define CUWU_MAX_EMOT_L 3
#define CUWU_MIN_EMOT_L 2

#define CUWU_NB_EMOT (1 << 3)

/* you can #define CUWU_INLINE inline  */
#ifndef CUWU_INLINE
#define CUWU_INLINE
#endif

/* This MUST be a power of 2 */
static const char cuwu_emot[CUWU_NB_EMOT][CUWU_MAX_EMOT_L + 1] = {
	"^^",
	":3",
	"UwU",
	"o.O",
	"UwU",
	":p",
	"Nya",
	"0w0"
};

/**
 * convert 'in' to an uwuified string, store result in 'out'
 * out must be at last 'in' size, 'extra_len' contain bow much bigger 'out' is than 'in' (in byte).
 * the extra size is use to store emotes and sure.
 */
static CUWU_INLINE int cuwuify(const char *in, char *out, int extra_len)
{
	static int emote_idx;
	int was_blank = 0;

	for (; *in; ++in) {
		char c = *in;

		if (c >= 'A' && c <= 'Z')
			c = c - ('A' - 'a');
		if (c == 'l' || c == 'r') {
			*out++ = 'w';
		} else if ((c == '.' || c == ',') &&
			   (*(in + 1) == ' ') &&
			   extra_len > CUWU_MAX_EMOT_L) {
			/*
			 * i++ & (CUWU_NB_EMOT - 1) is a
			 * chear i % CUWU_NB_EMOT but work only for power of 2
			 */
			const char *emot = cuwu_emot[emote_idx &
						     (CUWU_NB_EMOT - 1)];
			++emote_idx;
			int i;

			*out++ = c;
			/* I do assume the compiller can easilly unroll this */
			for (i = 0; i < CUWU_MIN_EMOT_L; ++i)
				*out++ = *emot++;
			for (i = 0; i < CUWU_MAX_EMOT_L && *emot; ++i)
				*out++ = *emot++;
			extra_len -= CUWU_MAX_EMOT_L;
		} else if (c == ' ' || c == '\t') {
			was_blank = 1;
			*out++ = c;
		} else if (was_blank) {
			was_blank = 0;
			if ((emote_idx++ & 1) == 0 &&
			    extra_len > 2 &&
			    (c == 'p' || c == 'm' || c == 'b' || c == 's')) {
				*out++ = c;
				*out++ = '-';
				extra_len -= 2;
			}
			*out++ = c;
		} else {
			*out++ = c;
		}
	}
	*out = 0;
	return 0;
}

#endif /* CUWU */
