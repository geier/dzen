/* ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <geier@lostpackets.de> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Christian Geier
 * ----------------------------------------------------------------------------
 */

#include "color.h"

void HSVtoRGB(float *r, float *g, float *b,
              float h, float s, float v)
{
	float hh, var1, var2, var3;
	int i;
	if ( s == 0 ) {  /*grey */
		*r = v;
		*g = v;
		*b = v;
		return;
	}
	hh = h/60.0;
	i = (int) hh;
	var1 = v * ( 1.0 - s);
	var2 = v * ( 1.0 - s * ( hh - i ) );
	var3 = v * ( 1.0 - s * (1.0 - (hh - i ) ) );

	switch ( i )  {
		case 0:
			*r = v;
			*g = var3;
			*b = var1;
			break;
		case 1:
			*r = var2;
			*g = v;
			*b = var1;
			break;
		case 2:
			*r = var1;
			*g = v;
			*b = var3;
			break;
		case 3:
			*r = var1;
			*g = var2;
			*b = v;
			break;
		case 4:
			*r = var3;
			*g = var1;
			*b = v;
			break;
		case 5:
			*r = v;
			*g = var1;
			*b = var2;
			break;
	}
}

