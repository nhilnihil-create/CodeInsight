#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<(ll)(b);i++)
#define FORR(i,a,b) for(ll i=a-1;i>=(ll)(b);i--)

#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める

#define INF 1000000000000 //10^12:極めて大きい値,∞
#define MOD 1000000007 //10^9+7:合同式の法
#define MAXR 100000 //10^5:配列の最大のrange(素数列挙などで使用)

#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

#define popcount __builtin_popcount

int main(void){
    int n, k;
    cin >> n >> k;
    ll a[n];
    ll ans = INF;
    ll i, j;
    memset(a, 0, sizeof(a));

    FOR(i, 0, n){
        cin >> a[i];
    }

    FOR(i, 0, pow(2, n)){
        //cout << i << ' ' << popcount(i) << ' ' << (popcount(i) != k) << endl;
        if (popcount(i) != k) continue;
        ll now = 0, cnt = 0;
        FOR(j, 0, n){
            if ((i >> j) & 1){
                if (a[j] <= now){
                    cnt += (now - a[j]) + 1;
                    //cout << now << ' ' << a[j] << ' '<< (now - a[j]) + 1 << endl;
                    now++;
                }
                now = max(now, a[j]);
            } else{
                now = max(now, a[j]);
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}
