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
    int n; cin >> n;
    vector<ll> A(n); rep(i, n) cin >> A[i];
    if(n==1 || n==2)cout << 1 << ln;
    else{
        int cnt = 1, bef = A[1], up;
        if(A[0]<A[1])up = true;
        else if(A[0]>A[1])up = false;
        else up = -1;
        rept(i, 2, n){
            //cout << cnt << " ";
            int a = A[i];   
            //cout << bef << "->" << A[i] << ln;
            if(up==1 && bef > A[i]){
                up = -1;
                cnt++;
            }else if(up==0 && bef < A[i]){
                up = -1;
                cnt++;
            }else{
                if(bef<A[i])up = true;
                else if(bef>A[i])up = false;
            } 
            bef = A[i]; 
        }
        cout << cnt << ln;
    }
}
