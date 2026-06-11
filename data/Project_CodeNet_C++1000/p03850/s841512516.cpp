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

int N;
int A[111111];

int sumabs[111111];
int sum[111111];
int dp[111111];
signed main(){
    cin>>N;
    rep(i,N){
        char op='+';
        if(i)cin>>op;
        cin>>A[i];
        if(op=='-')A[i]*=-1;
    }

    rep(i,N)sumabs[i+1]=sumabs[i]+abs(A[i]);
    rep(i,N)sum[i+1]=sum[i]+A[i];

    vint pos;
    rep(i,N)if(A[i]<0)pos.pb(i);

    int ans=accumulate(A,A+N,0ll);

    for(int i=0;i+1<pos.size();i++){
        int x=pos[i];
        int y=pos[i+1];
        int tmp=sum[x+1];
        tmp-=sum[y]-sum[x+1];
        tmp+=sumabs[N]-sumabs[y];
        chmax(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
