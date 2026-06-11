#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll x;
    sc(x)
    ll ans = (x / 11) * 2;
    if (x % 11 > 0) ans += 1;
    if (x % 11 > 6) ans += 1;
    cout << ans << endl;
    return 0;
}