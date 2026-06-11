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
    
    int n;
    string s;
    cin >> n >> s;
    char key[] = {'(', ')'};
    rep(j, 2) {
        {   
            int cnt = 0;
            rep(i, sz(s)) {
                if (s[i] == key[j]) {
                    cnt++;
                } else {
                    if (cnt > 0) {
                        cnt--;
                    }
                }
            }
            s += string(cnt, key[1-j]);
        }
        reverse(s.begin(), s.end());
    
    }
    cout << s << endl;
}