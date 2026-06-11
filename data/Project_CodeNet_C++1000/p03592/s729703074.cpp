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

    int n, m, k;
    cin >> n >> m >> k;

    bool b = false;

    for (int i = 0; i <= n; i++) {
        int cnt1 = 0;
        cnt1 += m * i;
        for (int j = 0; j <= m; j++) {
            int cnt2 = cnt1;
            cnt2 += (n - i) * j;
            cnt2 -= i * j;

            if (cnt2 == k) {
                b = true;
            }
        }
    }

    if(b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}