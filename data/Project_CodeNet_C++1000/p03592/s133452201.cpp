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
    long long N, M, K, i, j, judge=0;

    cin >> N >> M >> K;

    if(K%N==0) judge = 1;
    if(K%M==0) judge = 1;

    if(N>=2 && M>=2){
        for(i=1; i<=N-1; i++){
            for(j=1; j<=M-1; j++){
                if(i*j + (N-i)*(M-j) == K) judge = 1;
            }
        }
    }

    if(judge==1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}