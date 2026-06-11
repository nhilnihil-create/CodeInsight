//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
void solve(){
    int h, w, n;
    cin >> h >> w >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int idx = 0;
    vector<vi> v(h, vi(w));
    for (int i = 0; i < h; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < w; ++j) {
                v[i][j] = idx + 1;
                a[idx]--;
                if (a[idx] == 0) idx++;
            }
        } else {
            for (int j = w - 1; j >= 0; j--) {
                v[i][j] = idx + 1;
                a[idx]--;
                if (a[idx] == 0) idx++;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << v[i][j] << ' '; 
        }
        cout << endl;
    } 
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}