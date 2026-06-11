#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;

int main(){
    constexpr long long mod=1e9+7;
    int N;cin>>N;
    vector<int> x(N);
    REP(i, N) cin >> x[i];
    vector<int> A(N),rank(N);
    A[0]=(x[0]-1);rank[0]=1;
    REP(i,N-1){
        A[i+1]=A[i]+x[i+1]-x[i]-1;
        rank[i+1]=max(rank[i],x[i]/2-A[i]+1);
    }
    long long ans=1;
    REP(i,N){
        long long k=upper_bound(All(rank),i+1)-rank.begin();
        ans=ans*(k-i)%mod;
    }
    cout<<ans<<endl;
}