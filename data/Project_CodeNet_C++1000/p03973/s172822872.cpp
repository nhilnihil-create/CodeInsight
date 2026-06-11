#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N; cin >> N;
    vector<int> a(N);
    rep(i,N) cin >> a[i];
    ll ans = 0;
    int now = 1;
    int M = 1;
    rep(i,N){
        int d = 0;
        int cnt = 0;
        if(i != 0 && a[i] % now == 0){
            if(a[i] >= now+1){
                a[i] -= now+1;
                d++;
                cnt++;
            }
        }
        d += (a[i]+now-1)/now-1;
        ans += d;
        int r = a[i]-(d-cnt)*now;
        now = max(r+1,M);
        M = max(r+1,M);
    }
    cout << ans << endl;
}

    

