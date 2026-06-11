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
    int n, k; cin >> n >> k;
    vector<ll> A(n); ll sum = 0;
    rep(i, n){
        cin >> A[i];
        if(A[i]>0)sum += A[i];
    }
    int index = 0;
    ll sei = 0, fu = 0, res = -LINF;
    for(index; index < k; index++){
        if(A[index]>0) sei += A[index];
        else fu += A[index];
        res = max(sum - sei, sum + fu);
    }
    for(index; index < n; index++){
        //cout << "sei:" << sei << " fu:" << fu << ln;
        if(A[index]>0) sei += A[index];
        else fu += A[index];
        if(A[index-k]>0) sei -= A[index-k];
        else fu -= A[index-k];
        chmax(res, sum - sei);
        chmax(res, sum + fu);
    }
    cout << res << ln;
}
