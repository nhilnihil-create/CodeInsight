#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

const int INF = 1001001001;

int main()
{
    int n;
    cin >> n;
    int mi = 810, mx = -810;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }

    if(mi == mx) {
        cout << 0 << endl;
        return 0;
    }

    int ans = INF;
    for(int i = mi; i <= mx; i++) {
        int t = 0;
        rep(j, n) {
            t += (a[j] - i) * (a[j] - i); 
        }
        ans = min(ans, t);
    }

    cout << ans << endl;
    

    return 0;
}
