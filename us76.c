/* MIT License
 * 
 * Copyright (c) 2017 R. Hartley
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <math.h> /* pow, exp */
#include "us76.h"


int atmo_us76_ratios_met(double alt, double* sigma, double* delta, double* theta)
{
     double rearth = 6369.0; /* radius of the Earth (km) */
     double GMR = 34.163195; /* hydrostatic constant */

     /* height of each layer base */
     double htab[] = {0.0, 11.0, 20.0, 32.0, 47.0, 51.0, 71.0, 84.852};

     /* temperature at base of each layer */
     double ttab[] = {288.15, 216.65, 216.65, 228.65, 270.65, 270.65, 
          214.65, 186.946};

     /* pressure at base of each layer */
     double ptab[] = {1.0, 2.233611E-1, 5.403295E-2, 8.5666784E-3, 
          1.0945601E-3, 6.6063531E-4, 3.9046834E-5, 3.68501E-6};

     /* temperature gradient in each layer */
     double gtab[] = {-6.5, 0.0, 1.0, 2.8, 0.0, -2.8, -2.0, 0.0};

     double h; /* geopotential altitude */
     int ilayer; /* index of current layer */
     double tgrad; /* local temperature gradient */
     double tbase; /* base temperature of this layer */
     double deltah; /* height above base of this layer */
     double tlocal; /* local temperature */


     /* ensure altitude is in in range. */
     if( alt>86 || alt<0 ) {
          return STDATMO_ERROR_ALT_RANGE;
     }

     /* convert geometric to geopotential altitude */
     h = alt*rearth/(alt+rearth);

     /* locate appropriate layer */
     for( ilayer=0;ilayer<8;ilayer++ ) {
          if( h<=htab[ilayer] )
               break;
     }

     tgrad=gtab[ilayer];
     tbase=ttab[ilayer];
     deltah=h-htab[ilayer];
     tlocal=tbase+tgrad*deltah;
     *theta=tlocal/ttab[0]; /* temperature ratio */

     /* pressure ratio */
     if( tgrad == 0.0 ) {            
          *delta=ptab[ilayer]*exp(-GMR*deltah/tbase);
     } else {
          *delta=pow(ptab[ilayer]*(tbase/tlocal),(GMR/tgrad));
     }

     *sigma=(*delta)/(*theta);  /*  density ratio */

     return STDATMO_SUCCESS;
}


