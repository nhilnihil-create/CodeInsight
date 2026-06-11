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

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    int x1 = 0, x2 = w, y1 = 0, y2 = h;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if(a == 1) {
            x1 = max(x1, x);
        } else if(a == 2) {
            x2 = min(x2, x);
        } else if(a == 3) {
            y1 = max(y1, y);
        } else {
            y2 = min(y2, y);
        }
    }

    int ans = max(0, -x1+x2) * max(0, -y1+y2);

    cout << ans << endl;

    return 0;
}
