#include<iostream>
#include<stack>
#include<queue>
#include<map>
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
    ll n, m, ans;
    sc(n) sc(m)
    if (n * 2 < m) ans = (m - 2 * n) / 4 + n;
    else if (n * 2 == m) ans = n;
    else if (n * 2 > m) ans = m / 2;
    cout << ans << endl;
    return 0;
}