#include <bits/stdc++.h>
using namespace std;

template<typename T>
using reversed_priority_queue = \
    std::priority_queue<T, std::vector<T>, std::greater<T> >;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef pair<ll, ll> PLL;

signed main() {
    ll N;
    cin>>N;
    vector<ll> a(3*N);
    rep(i,0,3*N){
        cin>>a[i];
    }

    // maxv[i]: [0 i]の間で最大N個の合計値
    vector<ll> maxv(3*N,0);
    {
        ll s = 0;
        reversed_priority_queue<ll> q;
        rep(i,0,N){
            s += a[i];
            q.push(a[i]);
        }
        maxv[N-1] = s;
        rep(k,N,3*N){
            if (a[k] > q.top()) {
                s -= q.top();
                s += a[k];
                q.pop();
                q.push(a[k]);
            }
            maxv[k] = s;
        }
    }

    // minv[i]: [0 i]の間で最大N個の最小値
    vector<ll> minv(3*N,0);
    {
        ll s = 0;
        priority_queue<ll> q;
        rep(i,2*N,3*N){
            s += a[i];
            q.push(a[i]);
        }
        minv[2*N] = s;
        for (ll k=2*N-1; k>=0; k--) {
            if (a[k] < q.top()) {
                s -= q.top();
                s += a[k];
                q.pop();
                q.push(a[k]);
            }
            minv[k] = s;
        }
    }

    ll ans = -10e15;
    rep(k,N,2*N+1){ // [0 k)が前半、[k 3N)が後半
        // printf("maxv[%d]=%d minv[%d]=%d\n",k-1,maxv[k-1],k,minv[k]);
        ans = max(ans, maxv[k-1] - minv[k]);
    }
    cout<<ans<<endl;
    return 0;
}
