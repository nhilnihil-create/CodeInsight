#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

const ll INF = 1e16;

int main(){
    int N;cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    vector<ll> sum(N+1);
    for(int i=0;i<N;i++){
        sum[i+1] = sum[i]+a[i];
    }
    ll res = INF;
    for(int i=1;i<N;i++){
        res = min(res,abs(sum[i]-(sum[N]-sum[i])));
    }
    cout << res << endl;
    return 0;
}