#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    ll n, k;
    cin >> n >> k;
    vl a(n+1);
    rep(i,1,n+1) {
        cin >> a[i];
    }
    vl b(n+1);
    rep(i,1,n+1) {
        b[i] = max(a[i],0LL);
        b[i] += b[i-1];
    }
    /*rep(i,1,n+1) {
        cout << b[i] << " ";
    }
    cout << endl;*/
    vl c(n+1);
    rep(i,1,k+1) {
        c[1] += a[i];
    }
    rep(i,2,n-k+2) {
        c[i] = c[i-1] - a[i-1] + a[i+k-1];
    }

    ll ret = 0;
    rep(i,1,n-k+2) {
        ll locret = b[i-1] + b[n] - b[i+k-1] + max(c[i],0LL);
        ret = max(ret, locret);
    }
    cout << ret << '\n';
    return 0;
}
