#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <stack>
#include <queue>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, A[100001], S[100001], judge[100001], ans=0;

    cin >> N;

    S[0] = 0;

    for(i=1; i<=N; i++){
        cin >> A[i];
    }

    sort(A+1, A+N+1);

    for(i=1; i<=N; i++){
        S[i] = S[i-1]+A[i];
    }

    for(i=1; i<=N-1; i++){
        if(S[i]*2 < A[i+1]) judge[i] = 0;
        else judge[i] = 1;
    }

    judge[N] = 1;

    for(i=N; i>=1; i--){
        if(judge[i]==1) ans++;
        else break;
    }

    cout << ans << endl;

    return 0;
}