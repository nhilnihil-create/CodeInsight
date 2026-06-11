#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;
 
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> imos(2 * m, 0);
    vector<ll> lazy(2 * m, 0);
    ll sum = 0;
    rep(i, n - 1)
    {
        int l = a[i];
        int r = a[i + 1];
        if (l > r)
            r += m;
        sum += r - l;
        if (r - l <= 1)
            continue;
        imos[l + 2] += 1;
        imos[r + 1] -= 1;
        lazy[r + 1] -= r + 1 - (l + 2);
    }
    //rep(i, 2 * m) cout<<imos[i]<<endl;
    rep(i, 2 * m)imos[i + 1] += imos[i];
    lazy[0]+=imos[0];
    rep(i, 2 * m){
        lazy[i + 1] += lazy[i] + imos[i+1];
    }
    vector<ll> ans(m,0);
    rep(i,m)ans[i]=lazy[i]+lazy[i+m];
    cout << sum - (*max_element(all(ans))) << endl;
}