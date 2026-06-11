/**
*    created: 27.06.2020 18:35:10
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcountll(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;
    map<int,int> mp;
    int t = 1;
    while (true) {
        int rem = (a * t) % b;
        if (rem == c) {
            cout << "YES" << endl;
            return 0;
        }
        else if (mp[rem] > 0) {
            cout << "NO" << endl;
            return 0;
        }
        else {
            mp[rem]++;
            t++;
        }
    }
    return 0;
}