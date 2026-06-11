#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int sa[100005], sb[100005], ta[100005], tb[100005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    rep(i,s.size()){
        sa[i+1] = sa[i] + (s[i] == 'A');
        sb[i+1] = sb[i] + (s[i] == 'B');
    }
    rep(j,t.size()){
        ta[j+1] = ta[j] + (t[j] == 'A');
        tb[j+1] = tb[j] + (t[j] == 'B');
    }
    int q;
    cin >> q;
    rep(qi,q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int Sa = (sa[b] - sa[a-1]) % 3;
        int Sb = (sb[b] - sb[a-1]) % 3;
        int Ta = (ta[d] - ta[c-1]) % 3;
        int Tb = (tb[d] - tb[c-1]) % 3;
        bool ok = false;
        rep(i,3){
            int A = (Sa + i) % 3;
            int B = (Sb + i) % 3;
            if(A == Ta && B == Tb){
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
