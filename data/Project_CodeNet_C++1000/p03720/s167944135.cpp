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


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
\
#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;


int main() {
    int n,m,a,b;
    int ans[51];
    cin >> n >> m;

    REP(i,51) ans[i] = 0;

    for(int i = 0; i < m; i ++){
        cin >> a >> b;
        ans[a] ++;
        ans[b] ++;
    }

    for(int i = 1; i <=  n; i ++){
        cout << ans[i] << endl;
    }
}





