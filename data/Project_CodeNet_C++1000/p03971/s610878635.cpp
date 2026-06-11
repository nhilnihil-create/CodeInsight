#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    int n, a, b; string s; cin >> n >> a >> b >> s;
    int len = s.size(), cnt = 0, b_ = 0;
    vector<string> ans(len);
    rep(i, len){
        char c = s[i];
        if(c=='c')ans[i] = "No";
        else if(c=='a'){
            if(cnt < a+b){ans[i] = "Yes"; cnt++;}
            else ans[i] = "No";
        }else{
            b_++;
            if(cnt < a+b && b_ <= b){ans[i] = "Yes"; cnt++;}
            else ans[i] = "No";
        }
    }
    rep(i, len)cout << ans[i] << ln;
}

