#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int n,p;
    cin >> n >> p;
    cout << fixed << setprecision(0);
    vector<bool> a(n);
    bool b = 0;
    rep(i,n){
        int in;cin >> in;
        if(in%2)b = true;
    }
    if(!b){
        if(p)cout << 0 << endl;
        else cout << pow(2,n) << endl;
    }else cout << pow(2,n-1) << endl;
    return 0;
}