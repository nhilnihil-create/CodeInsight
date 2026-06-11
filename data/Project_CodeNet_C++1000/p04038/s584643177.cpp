#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
const int FACT_SIZE=9111111;
int fact[FACT_SIZE];
int inv[FACT_SIZE];
struct fact_exec{
    fact_exec(){
        fact[0]=1;
        for(int i=1;i<FACT_SIZE;i++)fact[i]=fact[i-1]*i%mod;
        inv[FACT_SIZE-1]=mpow(fact[FACT_SIZE-1],mod-2);
        for(int i=FACT_SIZE-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    }
}factexec;
int nCk(int n,int k){
    if(n<0|k<0||k>n)return 0;
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}
int nPk(int n,int k){
    if(n<0||k<0||k>n)return 0;
    return fact[n]*inv[n-k]%mod;
}

int dp[2222][2222];

signed main(){
    int N,K;
    cin>>N>>K;

    if(K==1){
        cout<<1<<endl;
        return 0;
    }

    dp[0][0]=1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i<N&&i<=j)add(dp[i+1][j],dp[i][j]);
            if(j<N){
                add(dp[i][j+1],dp[i][j]*nCk(K-2+i-1+j*(K-1),K-2)%mod);
            }
        }
    }

    cout<<dp[N][N]*fact[N]%mod<<endl;

    return 0;
}
