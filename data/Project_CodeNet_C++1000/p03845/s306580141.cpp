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
    int t[101];
    int p[101];
    int x[101];
    int n,m;
    int ans = 0;

    cin >> n;
    for(int i = 0; i < n; i ++) cin >> t[i];
    cin >> m;
    REP(i,m) cin >> p[i] >> x[i];

    REP(i,m){
        ans = 0;
        for(int j = 0; j < n; j ++){
            if(j+1 == p[i]) ans += x[i];
            else ans += t[j];
        }
        cout << ans << endl;
    }


    return 0;
}









