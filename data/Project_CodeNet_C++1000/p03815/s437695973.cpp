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
    ll x;
    cin >> x;

    ll ans = 0;
    if(x <= 6) ans = 1;
    else if(x <= 11) ans = 2;
    else {
        ans = (x / 11 * 2);
        if(x % 11 != 0) {
            if(x % 11 <= 6) ans += 1;
            else ans += 2;
        } 
    }

    cout << ans << endl;

    return 0;
}
