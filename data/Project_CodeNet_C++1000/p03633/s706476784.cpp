#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip> // setprecisionを使用するのに必要 cout << fixed << setprecision(15) << p でpを小数点以下15桁表示
using namespace std;
#define REPD(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) REPD(i, 0, n)
typedef long long ll;
#define fin(ans) cout << (ans) << '\n'
/*

*/
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll gcdmul(ll a,ll b){
    return (a < b)? b/gcd(a,b)*a:a/gcd(a,b)*b;
}

int main()
{
    int N;
    cin >> N;
    ll temp;
    ll ans = 1;
    REP(i,N){
        cin >> temp;
        ans = gcdmul(ans,temp);
    }
    fin(ans);
    return 0;
}