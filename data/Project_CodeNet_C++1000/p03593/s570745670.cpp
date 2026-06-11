#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    map<char, int> mp;
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            mp[s[j]]++;
        }
    }
    int cnt4 = 0;
    int cnt2 = 0;
    int cnt1 = 0;
    for (auto&& p : mp) {
        cnt4 += p.se/4;
        p.se -= (p.se/4) * 4;
        cnt2 += p.se/2;
        p.se -= (p.se/2) * 2;
        cnt1 += p.se;
    }
    if (h % 2 == 0 && w % 2 == 0) {
        if (h * w == 4 * cnt4) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (h % 2 == 0) {
        if (h * w == 4 * cnt4 + 2 * cnt2 && cnt2 <= h/2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (w % 2 == 0) {
        if (h * w == 4 * cnt4 + 2 * cnt2 && cnt2 <= w/2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (cnt1 == 1 && cnt2 <= (h+w-2)/2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}