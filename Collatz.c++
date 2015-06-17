// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ----------
// calc_cycle
// ----------
int calc_cycle (int n) {
    assert(n > 0);
    int c = 1;

    while(n > 1){
        if(!(n % 2)){ n /= 2;}
        else { n *= 3; ++n;}
        ++c;
    }

    assert(c > 0);
    return c;
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int max = 0;
    while(i <= j){
        int val = calc_cycle(i);
        if(val > max) {max = val;}
        ++i;
    }

    return max;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
