#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main(void) {
    string s;
    cin >> s;
    int k;
    cin >> k;

    vector<char> C;
    rep (i, 2) for (char c = 'a'; c <= 'z'; c++) C.pb(c);

    for (int i = 0; i < s.size(); i++) {
        if (i != s.size() - 1) {
            if (s[i] == 'a') continue;
            if (26 - (s[i] - '0' - 48) + 1 <= k) {
                k -= 26 - (s[i] - '0' - 48) + 1;
                s[i] = 'a';
            }
        }
        else {
            s[i] = C[(s[i] - '0' - 48 - 1 + k % 26)];
        }
        //cout << i << " " << k << endl;
    }


    //cout << 'z' - '0' - 48 << endl; 26

    cout << s << endl;
    return 0;
}