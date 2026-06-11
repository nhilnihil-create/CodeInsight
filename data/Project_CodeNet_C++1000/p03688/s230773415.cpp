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
    sort(all(a));
    if(a[n-1] - a[0] > 1) {
        cout << "No" << '\n';
        return 0;
    }
    int x,y;
    x = 0, y = 0;
    rep(i,0,n) {
        if(a[i] == a[0]) {
            x++;
        } else {
            y++;
        }
    }
    if(x == n) {
        if(a[0] == n-1) {
            cout << "Yes" << '\n';
        } else {
            if(a[0] * 2 <= n) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    } else {
        if(a[0] >= x && a[n-1] <= x + y/2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}
