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
    int n;
    cin >> n;
    vi a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    si s;
    s.insert(-1);
    s.insert(n);
    vi idx(n+1);
    rep(i,0,n) {
        idx[a[i]] = i;
    }
    ll ret = 0;
    rep(i,1,n+1) {
        int j = idx[i];
        s.insert(j);
        auto it = s.lower_bound(j);
        --it;
        auto jt = s.upper_bound(j);
        int left = j - *it;
        int right = *jt - j;
        ret += (ll)left * right * i;
    }
    cout << ret << endl;
    return 0;
}
