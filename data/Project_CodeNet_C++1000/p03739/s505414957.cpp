#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

long int M = 1e+9+7;
int inf = 1e+9;

ll solve(ll ans,ll sum,vi a,int n){
    ll sa;
    srep(i,1,n){
        if(sum > 0){
            sum+=a[i];
            if(sum > -1){
                sa = sum+1;
                sum-=sa;
                ans+=sa;
            }
        }else if(sum < 0){
            sum+=a[i];
            if(sum < 1){
                sa = 1-sum;
                sum+=sa;
                ans+=sa;
            }
        }
    }
    return ans;
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int n;
    cin >> n;
    vi a(n);
    rep(i,n){
        cin >> a[i];
    }

    ll psum=a[0];
    ll msum=a[0];
    ll pans=0,mans=0;
    if(psum < 1){
        ll sa = 1-psum;
        psum+=sa;
        pans+=sa;
    }
    if(msum > -1){
        ll sa = msum+1;
        msum-=sa;
        mans+=sa;
    }

    pans = solve(pans,psum,a,n);
    mans = solve(mans,msum,a,n);
    cout << min(pans,mans) << endl;
    return 0;
}