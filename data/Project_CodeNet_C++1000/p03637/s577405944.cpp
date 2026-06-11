#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

int main() {
    int n;
    cin >> n;
    vi a(n);
    int b0 = 0, b1 = 0, b2 = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            if(a[i] % 4 == 0) b2++;
            else b1++;
        } else {
            b0++;
        }
    }

    bool can = false;
    if(b1 == 0) {
        if(b2 + 1 >= b0) can = true;
    } else if(b2 >= b0) can = true;

    Yn(can);

    return 0;
}
