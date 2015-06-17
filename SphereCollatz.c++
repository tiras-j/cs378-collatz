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
#include <vector>   // vector

using namespace std;

#ifdef ONLINE_JUDGE
    #define NDEBUG
#endif

#define CACHE_SIZE 100000
#define CACHE_ACCESS(A) (((A) < CACHE_SIZE) ? cache[(A)] : 0)

// -------
// globals
// -------
int cache[CACHE_SIZE] = {};
vector<int> queue;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// -------------
// process_queue
// -------------
void process_queue(int cycles) {
    for(unsigned int i = 0; i < queue.size(); ++i){
        int v = queue[i];
        if(v < CACHE_SIZE) 
            cache[v] = cycles;
        --cycles;
    }
    queue.clear();
}

// ----------
// calc_cycle
// ----------
int calc_cycle (int n) {
    assert(n > 0);
    int c = 1;

    // Exit early on cache value
    if(CACHE_ACCESS(n))
        return cache[n];

    while(n > 1){
        queue.push_back(n);
        if(!(n % 2)){ n /= 2;}
        else { n *= 3; ++n;}

        if(CACHE_ACCESS(n)){
            c = c + cache[n];
            break;
        }else{++c;}
    }

    assert(c > 0);
    process_queue(c);
    return c;
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    int max = 0;    

    if(i > j){i^=j;j^=i;i^=j;}
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

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}

