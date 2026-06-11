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
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    ll ansp=0LL;
    ll ansm=0LL;
    ll sump=0LL;
    ll summ=0LL;


    rep(i, n) {
        if(i&1) {
            if(a[i]+sump > 0) {
                sump += a[i];
            } else {
                ansp += 1LL - (a[i]+sump);
                sump = 1LL;
            }
            if(a[i]+summ < 0) {
                summ += a[i];
            } else {
                ansm += (a[i]+summ) + 1LL;
                summ = -1LL;
            }
            
        } else {
            if(a[i]+summ > 0) {
                summ += a[i];
            } else {
                ansm += 1LL - (a[i]+summ);
                summ = 1LL;
            }
            if(a[i]+sump < 0) {
                sump += a[i];
            } else {
                ansp += (a[i]+sump) + 1LL;
                sump = -1LL;
            }
        }
    }

    cout << min(ansm, ansp) << endl;
}