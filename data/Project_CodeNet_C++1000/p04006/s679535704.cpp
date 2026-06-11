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

ll n, x;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n >> x;
    vl a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    vl b = a;
    ll ret = LLONG_MAX;
    rep(i,0,n) {
        rep(j,0,n) {
            b[j] = min(b[j], a[(j-i+n)%n]);
        }
        ll locret = 0;
        rep(j,0,n) {
            locret += b[j];
        }
        locret += i * x;
        ret = min(ret, locret);
    }
    cout << ret << endl;
    return 0;
}
