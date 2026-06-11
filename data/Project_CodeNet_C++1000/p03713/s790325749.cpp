#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long h, w;
long long sa, sb, sc;
long long sb2, sc2;
long long smin(long long H, long long W, long long S) {
    long long rans = 1e12;
    for(int i = 0; i <= H; ++i) {
        vector<long long> ss;
        vector<long long> ss2;
        sa = i*W;
        if((H-i) % 2 == 0 || W % 2 == 0) {
            sb = sc = (S-sa) / 2;
            sb2 = sc2 = (S-sa) / 2;
        }else {
            sb = (H-i)/2 * W;
            sc = S - sa - sb;
            sb2 = (H-i) * (W/2);
            sc2 = S - sa - sb2;
        }
        ss.push_back(sa); ss.push_back(sb); ss.push_back(sc);
        ss2.push_back(sa); ss2.push_back(sb2); ss2.push_back(sc2);
        sort(ss.begin(), ss.end());
        sort(ss2.begin(), ss2.end());
        chmin(rans, ss.at(2)-ss.at(0));
        chmin(rans, ss2.at(2)-ss2.at(0));
        /*for(int i = 0; i < 3; ++i) {
            cout << ss.at(i) << " " << ss2.at(i) << endl;
        }*/
    }
    return rans;
}

int main() {
    cin >> h >> w;
    long long s = h * w;
    long long sa, sb, sc;
    long long ans = 1e12;
    if(h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
    }else {
        if(h == w) {
            cout << smin(h, w, s) << endl;
        }else {
            cout << min(smin(h, w, s), smin(w, h, s)) << endl;
        }
    }
}