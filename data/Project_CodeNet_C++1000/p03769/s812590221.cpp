//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ll n;
    cin >> n;
    vi num(200);
    rep(i, 100) {
        num[i] = i+1;
    }
    n++;

    int now = 0, cou = 0;
    ll x = 1;
    while(n) {
        if(n&1) {
            num[100+now+cou] = 100-cou;
            cou++;
        }
        now++;
        n >>= 1;
    }
    now -= 2;
    rep(i, now) {
        int j = 100;
        while(num[j]) j++;
        num[j] = i+1;
    }

    vi::iterator itr = find(all(num), 0);
    int m = itr-num.begin()+1;
    cout << m << endl;
    rep(i, m) {
        if(i == m-1) i++;
        cout << num[i] << (i == m?'\n':' ');
    }
}