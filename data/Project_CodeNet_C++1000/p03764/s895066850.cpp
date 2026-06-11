#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e5 + 5;

typedef long long LL;

int n, m;
int x[maxn], y[maxn];
const LL mod = 1e9 + 7;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d", &x[i]);
    }
    for(int i = 1;i <= m;i++){
        scanf("%d", &y[i]);
    }
    LL pre1 = 0, pre2 = 0, suf1 = 0, suf2 = 0;
    for(int i = 1;i <= n;i++){
        pre1 += 1LL * (i - 1) * x[i];
    }
    for(int i = n;i >= 1;i--){
        suf1 += 1LL * (n - i) * x[i];
    }
    for(int i = 1;i <= m;i++){
        pre2 += 1LL * (i - 1) * y[i];
    }
    for(int i = m;i >= 1;i--){
        suf2 += 1LL * (m - i) * y[i];
    }
    pre1 = (pre1 % mod + mod) % mod;
    suf1 = (suf1 % mod + mod) % mod;
    pre2 = (pre2 % mod + mod) % mod;
    suf2 = (suf2 % mod + mod) % mod;
    LL ans = ((pre1 * pre2 + suf1 * suf2 - pre1 * suf2 - pre2 * suf1) % mod + mod) % mod;
    cout << ans << endl;
    return 0;
}
