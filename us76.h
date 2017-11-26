#ifndef __US76_H__
#define __US76_H__

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

#define STDATMO_SUCCESS            0
#define STDATMO_ERROR_ALT_RANGE   -1

/* Naming convention: atmo_(model name)_(function name)_(eng | met) */


/* Compute the properties of the 1976 standard atmosphere to 86 km.
 *
 * Inputs:
 *   alt       Geometric altitude, km
 *
 * Outputs:
 *   sigma     density/sea-level standard density
 *   delta     pressure/sea-level standard pressure
 *   theta     temperature/sea-level standard temperature
 *
 * Originial FORTRAN 90 code by Ralph Carmichael and part of Public Domain 
 * Aeronautical Software.
 *
 * http://www.pdas.com/programs/atmos.f90
 */
int atmo_us76_ratios_met(double alt, double* sigma, double* delta, double* theta);



/* TODO: add this */
/*int atmo_us76_ratios_eng(double alt, double* sigma, double* delta, double* theta); */


#endif
