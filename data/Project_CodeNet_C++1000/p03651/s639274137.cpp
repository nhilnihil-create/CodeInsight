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
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
using ld = long double;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// 最大公約数
ll gcd(ll a, ll b)
{
    if(a%b == 0){
        return(b);
    }
    else{
        return(gcd(b, a%b));
    }
}

int main(void)
{
    ll N, K, i, A[100001], max=0, gc;

    cin >> N >> K;
    
    for(i=1; i<=N; i++){
        cin >> A[i];

        chmax(max,A[i]);

        if(i==1) gc = A[1];
        else gc = gcd(gc,A[i]);
    }

    if(K%gc==0 && K<=max){
        cout << "POSSIBLE" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}