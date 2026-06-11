#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    int n; cin >> n;
    vector<string> s, t;
    for(int i=1; i<=n; i++){
        string a; cin >> a;
        if(i%2==1) s.push_back(a);
        else t.push_back(a);
    }

    if(n%2==0){
        for(int i=t.size()-1; i>=0; i--) cout << t[i] + " ";
        rep(i, s.size()) cout << s[i] + " ";
    }else{
        for(int i=s.size()-1; i>=0; i--) cout << s[i] + " ";
        rep(i, t.size()) cout << t[i] + " ";    
    }
    cout << ln;
}