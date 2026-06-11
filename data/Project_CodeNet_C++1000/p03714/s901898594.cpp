#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 301
#define INF (1LL << 50)
#define MAXN 300003
#define MAXM 100001
#define MAXK 100002
#define MAXP 1000001
#define MOD 1000000007
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll N;
ll a[MAXN];

int main(){
    cin >> N;
    for(ll i = 0;i < 3 * N;i++){
        cin >> a[i];
    }

    priority_queue<ll> qb;
    priority_queue<ll, vector<ll>, greater<ll>> qf;
    ll sumf[MAXN], sumb[MAXN];


    for(ll i = 0;i < N;i++){
        qf.push(a[i]);
        sumf[0] += a[i];
        qb.push(a[3 * N - i - 1]);
        sumb[N] += a[3 * N - i - 1];
    }

    for(ll i = 0;i < N;i++){
        sumf[i + 1] = sumf[i] + a[i + N];
        qf.push(a[i + N]);
        sumf[i + 1] -= qf.top();
        qf.pop();
    }

    for(ll i = N - 1;i >= 0;i--){
        sumb[i] = sumb[i + 1] + a[i + N];
        qb.push(a[i + N]);
        sumb[i] -= qb.top();
        qb.pop();
    }

    ll ans = -INF;
    for(ll i = 0;i <= N;i++){
        ans = max(ans, sumf[i] - sumb[i]);
    }

    printf("%lld\n", ans);
}