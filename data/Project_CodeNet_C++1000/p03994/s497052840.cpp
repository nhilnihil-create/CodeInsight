#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define all(a) a.begin(),a.end()
#define tmax(a,b,c) max(a,max(b,c))
#define tmin(a,b,c) min(a,min(b,c))
#define pb push_back
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
const int inf = 1001001001;

int main() {
    string s;
    int k;
    cin >> s >> k;
    rep(i,s.size()) {
        char& c = s[i];
        if(c == 'a') continue;
        int nexta = 'z'-c+1;
        if(nexta <= k) {
            k -= nexta;
            c = 'a';
        }
    }
    if(k > 0) {
        k %= 26;
        s[s.size()-1] += k;
        if(s[s.size()-1] > 'z') s[s.size()-1] -= 26;
    }
    cout << s << endl;
}