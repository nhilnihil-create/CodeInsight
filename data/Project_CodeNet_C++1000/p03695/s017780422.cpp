#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;

int main() {
    int n, tsuyoi = 0;
    cin >> n;
    vector<bool> v(8, false);
    rep(i, n) {
        int a;
        cin >> a;
        if (a < 400) v[0] = true;
        else if (a < 800) v[1] = true;
        else if (a < 1200) v[2] = true;
        else if (a < 1600) v[3] = true;
        else if (a < 2000) v[4] = true;
        else if (a < 2400) v[5] = true;
        else if (a < 2800) v[6] = true;
        else if (a < 3200) v[7] = true;
        else tsuyoi++;
    }
    int cnt = 0;
    rep(i, SZ(v)) {
        if(v[i]) cnt++;
    }
    cout << max(cnt, 1) << " " << cnt + tsuyoi << endl;
    
}