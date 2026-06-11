#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)
#define rep1(i, n) for(int i = 1; i <= (int) n; i++)
#define all(v) v.begin(),v.end()

int main() {
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    ll S = n;
    ll cc = m/2;
    ans = min(S,cc);
    cc -= ans;
    ans += max(0ll,cc/2);
    cout << ans << endl;
    return 0;
}