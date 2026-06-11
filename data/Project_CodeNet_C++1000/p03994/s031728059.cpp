#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
    cout << fixed << setprecision(10);
    string s;
    ll k;
    cin >> s >> k;
    rep(i,int(s.size())){
        int sub = 'z' - s[i]  + 1;
        if(sub <= k && i != int(s.size()) - 1 && s[i] != 'a'){
            s[i] = 'a';
            k -= sub;
        }
        if(sub <= k && i == int(s.size()) - 1){
            int subsub = (k - sub) % ('z' - 'a' + 1);
            s[i] = char('a' + subsub);
        }
        if(sub > k && i == int(s.size() - 1) ){
            s[i] = char(s[i] + k);
        }
    }
    cout << s << endl;
    return 0;
}
