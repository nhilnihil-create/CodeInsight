#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {

    string o,e;

    cin >> o >> e;

    for(int i = 0; i < e.length(); i ++){
        cout << o[i] << e[i];
    }

    if(o.length() - e.length() == 1) cout << o[o.length()-1];

    return 0;
}









