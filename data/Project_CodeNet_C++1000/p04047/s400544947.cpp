#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    int N, i, L[201], ans=0;

    cin >> N;

    for(i=1; i<=2*N; i++){
        cin >> L[i];
    }

    sort(L+1, L+2*N+1);

    for(i=1; i<=N; i++){
        ans += min(L[2*i-1], L[2*i]);
    }

    cout << ans << endl;

    return 0;
}