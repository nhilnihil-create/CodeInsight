//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;

    rep(i, n+1) {
        rep(j, m+1) {
            int x;
            x = i*j + (n-i)*(m-j);
            if(x == k) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}