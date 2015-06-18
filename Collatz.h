// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

#define USE_CACHE

// Relocating this symbol simply for gtest to 
// be able to acces via its include. Technically this
// does not (and SHOULD NOT) be exposed in a header file
#ifdef USE_CACHE
    #define CACHE_SIZE 100000
#endif
// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair
#include <vector>   // vector
using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);

#ifdef USE_CACHE
// -------------
// process_queue
// -------------
 /**
  * Process intermediate calculation values, values are stored in global queue
  * to avoid the cost of construction/destruction between stack frames
  * NOTE: Only included if USE_CACHE is defined
  * @param cycles a positive integer of cycle length
  */
void process_queue(int cycles);
#endif
// ----------
// calc_cycle
// ----------
 /**
  * Calculate the cycle length of a given integer
  * @param n a positive integer
  * @return an integer cycle length value
  */ 
int calc_cycle (int n);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

#endif // Collatz_h
