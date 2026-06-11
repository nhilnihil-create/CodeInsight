#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];

    ll x = 0, y = 0, z = 0;
    rep(i, n) {
        if (a[i] % 4 == 0) {
            x++;
        } else if (a[i] % 4 == 2) {
            y++;
        } else {
            z++;
        }
    }

    bool b = true;
    if (z - 1 <= x) {
        x -= (z - 1);
        if (y % 2) {
            if(x==0){
                b = false;
            }
        }
    }else{
        b = false;
    }

    if(b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}