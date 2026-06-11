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
    string s; cin >> s;
    int n = s.length();
    map<char,bool>mp;
    mp['N'] = false;
    mp['W'] = false;
    mp['S'] = false;
    mp['E'] = false;
    int ans = false;


    for(int i = 0; i < n; i ++){
        mp[s[i]] = true;
    }

    if(mp['N'] && mp['W'] && mp['S'] && mp['E']) ans = true;
    if(mp['N'] && !mp['W'] && mp['S'] && !mp['E']) ans = true;
    if(!mp['N'] && mp['W'] && !mp['S'] && mp['E']) ans = true;

    cout << ((ans)?"Yes":"No");

    return 0;
}









