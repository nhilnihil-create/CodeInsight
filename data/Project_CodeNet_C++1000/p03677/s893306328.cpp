#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<62)-1
#define MAX 1000000000
signed main(){
    int N,M; cin>>N>>M;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    vi B(M+1),C(M+1),D(M+1),E(M+1);
    int sum=0,memo=0;
    rep(i,1,N){
        if(A[i]<A[i-1]){
            int X=M-A[i-1];
            sum+=X;
            memo++;
            E[A[i]]++;
            D[A[i]]+=M-A[i-1]+A[i];
            C[A[i-1]]++;
        }
        else{
            C[A[i-1]]++;
            D[A[i]]+=A[i]-A[i-1];
            E[A[i]]++;
        }
    }
    int ans=0;
    REP(i,1,M){
        sum+=memo;
        ans=max(ans,sum-memo);
        memo-=E[i];
        sum-=D[i];
        memo+=C[i];
    }
    ans=-ans;
    rep(i,1,N){
        if(A[i-1]>A[i]) ans+=M-A[i-1]+A[i];
        else ans+=A[i]-A[i-1];
    }
    cout<<ans<<endl;
}

