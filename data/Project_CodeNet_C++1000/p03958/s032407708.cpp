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
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll K, T, i, a[101], ans=0, half;

    cin >> K >> T;

    if(K%2==0) half = K/2;
    else half = K/2+1;

    for(i=1; i<=T; i++){
        cin >> a[i];

        if(a[i]>half){
            ans += a[i]-(K-a[i])-1;
        }
    }

    cout << ans << endl;

    return 0;
}