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


int main() {  
    int n; cin >> n;
    vector<bool> col(10, false); int over = 0, und = 0;
    rep(i, n){
        int a; cin >> a;
        if(a >=3200)over++;
        else{
            if(col[a/400] == false){col[a/400] = true; und++;}
        }
    }
    cout << max(1, und) << " " << min(n, und+over) << ln;
}


