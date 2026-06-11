#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
  	if(n==k){
      return 1;
    }
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>>A(M);
    vector<bool>a(300000);
    vector<bool>b(300000);
    bool ans=false;
    rep(i,M){
        cin>>A[i].first;
        cin>>A[i].second;
        if(A[i].first==1||A[i].second==1){
            a[max(A[i].first,A[i].second)]=true;
        }
        else if(A[i].first==N||A[i].second==N){
            b[min(A[i].first,A[i].second)]=true;
        }
    }
    rep(i,300000){
        if(a[i]==true&&b[i]==true){
            ans=true;
            break;
        }
    }
    if(ans==true){
        cout<<"POSSIBLE"<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}






