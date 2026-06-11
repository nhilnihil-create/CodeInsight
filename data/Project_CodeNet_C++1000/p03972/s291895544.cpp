#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll w, h;
struct pqdata {
    ll cost; char x;
    bool operator<(const pqdata &r) const { return cost < r.cost; }
};

int main() {
    cin >> w >> h;
    vector<pqdata> pqvec;
    for(int i = 0; i < w; ++i) {
        pqdata indata;
        cin >> indata.cost;
        indata.x = 'p';
        pqvec.emplace_back(indata);
    }
    for(int i = 0; i < h; ++i) {
        pqdata indata;
        cin >> indata.cost;
        indata.x = 'q';
        pqvec.emplace_back(indata);
    }
    sort(pqvec.begin(), pqvec.end());

    int pqlen = pqvec.size();
    int pnow = h+1; int qnow = w+1;
    ll ans = 0;
    for(int i = 0; i < pqlen; ++i) {
        if(pqvec.at(i).x == 'p') {
            ans += pqvec.at(i).cost*pnow;
            qnow--;
        }else {
            ans += pqvec.at(i).cost*qnow;
            pnow--;
        }
    }
    cout << ans << endl;
}