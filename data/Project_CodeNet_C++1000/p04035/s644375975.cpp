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
    int n;
    ll l;
    cin >> n >> l;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int nn = -1;
    rep(i, n-1) {
        if(a[i] + a[i+1] >= l) {
            nn = i;
            break;
        }
    } 
    if(nn == -1) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;

    rep(i, nn) {
        cout << i+1 << endl;
    }    
    int j = n-2;
    while(j != nn) {
        cout << j--+1 << endl;
    }
    cout << nn+1 << endl;
}