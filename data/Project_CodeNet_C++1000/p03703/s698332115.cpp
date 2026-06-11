#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

struct BIT {
    typedef ll T;
    T n;
    vector<T> bit;

    // 各要素の初期値は 0
    BIT(T num) : bit(num+1, 0) { n = num; }

    // a_i += w
    void add(T i, T w) {
        for (T x = i; x <= n; x += x & -x) {
            bit[x] += w;
        }
    }
    // [1, i] の和を計算.
    T sum(T i) {
        T ret = 0;
        for (T x = i; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    }
    // [left+1, right] の和を計算.
    T sum(T left, T right) {
        return sum(right) - sum(left);
    }
}; // BIT bit(n);

int main() {
    ll N,K;cin>>N>>K;
    vector<ll> a(N,0),sum(N+1,0);
    rep(i,N) {
        cin>>a[i];
        a[i]-=K;
        sum[i+1] = sum[i] + a[i];
    }
    vector<ll> srt(N+1,0);
    srt = sum;
    sort(srt.begin(),srt.end());
    ll ans = 0;
    BIT bit(N+5);
    rep(i,N+1) {
        ll ord = lower_bound(srt.begin(),srt.end(),sum[i]) - srt.begin();
        ans += bit.sum(ord+1);
        // cout<<i<<" "<<ans<<" "<<ord<<endl;
        bit.add(ord+1,1);
    }
    cout<<ans<<endl;
}