/*      ░░█ ▄▀█ █   █▀ █░█ █▀█ █▀▀ █▀▀   █▀█ ▄▀█ █▀▄▀█  
        █▄█ █▀█ █   ▄█ █▀█ █▀▄ ██▄ ██▄   █▀▄ █▀█ █░▀░█     */


// [abc052_b.cpp] => [27-07-2020 @ 22:03:27] 
// Author & Template by : Udit "luctivud" Gupta
// https://www.linkedin.com/in/udit-gupta-1b7863135/


#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <time.h>
// #include <math.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <assert.h>

using namespace std;

typedef long long int lld;
typedef unsigned long long int llu;
typedef vector<int> v_int;
typedef vector<lld> v_lld;
typedef vector<llu> v_llu;
typedef pair<int, int> p_int;
typedef pair<lld, lld> p_lld;


#define   INDEPENDENT_CASES()  cin >> (T3X0); T353 = T3X0; while(T3X0--)
#define          _input(V3C0)  for(auto &V3C0_IT7 : (V3C0)) cin >> (V3C0_IT7)
#define     mems(A77AY, V4LU)  memset((A77AY), (V4LU), sizeof((A77AY)))
#define   CH3K(IT7, EN4, S7P)  (((S7P)<0) ? (IT7)>(EN4) : (IT7)<(EN4))
#define for4(IT7,ST4,EN4,S7P)  for(auto IT7=(ST4); CH3K(IT7,EN4,S7P); (IT7)+=(S7P))
#define    FORE4CH(IT7, V3C0)  for(auto IT7=(V3C0).begin(); IT7!=(V3C0).end(); IT7++)


// template<typename T> void _SC4N(T &x) { 
//     x = 0; bool neg = 0; 
//     register T c = getchar();
//     if (c == '-') neg = 1, c = getchar();
//     while ((c < 48) || (c > 57)) c = getchar();
//     for ( ; c < 48||c > 57 ; c = getchar());
//     for ( ; c > 47 && c < 58; c = getchar() ) x= (x << 3) + ( x << 1 ) + ( c & 15 );
//     if (neg) x *= -1;
// }





void solveEachTest(lld T35TC453N = 1) {
    // auto S34t = chrono:: high_resolution_clock::now(); 
    lld n; cin >> n;
    lld x = 0LL;
    lld ans = 0LL;
    for4(i, 0LL, n, 1LL) {
        char c; cin >> c;
        if (c == 'I') x++;
        else x--;
        ans = max(ans, x);
    }

    cout << ans;
    

    cout << "\n"; 

    // auto S34p = chrono::high_resolution_clock::now(); 
    // auto D34n = chrono::duration_cast<chrono::microseconds>(S34p - S34t);
    // cout << "Time Elapsed: " << D34n.count() / (long double) 1e6 << " seconds" << endl; 
    return;
}


signed main() {

    // ios_base::sync_with_stdio(false); cin.tie(0);

    lld T3X0 = 0, T353 = 1;

    // INDEPENDENT_CASES()
        solveEachTest(T353 - T3X0);
    return 0;
}
