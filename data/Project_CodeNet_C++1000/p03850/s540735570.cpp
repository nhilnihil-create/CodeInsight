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

int sum[111111];
int sumabs[111111];

signed main(){
    cin>>N;
    cin>>A[0];
    for(int i=1;i<N;i++){
        char c;
        cin>>c>>A[i];
        if(c=='-')A[i]*=-1;
    }

    rep(i,N)sum[i+1]=sum[i]+A[i];
    rep(i,N)sumabs[i+1]=sumabs[i]+abs(A[i]);

    vint lis;
    rep(i,N)if(A[i]<0)lis.pb(i);

    int ans=sum[N];

    for(int i=0;i+1<lis.size();i++){
        int x=lis[i];
        int y=lis[i+1];
        int tmp=sum[x];
        tmp-=sumabs[y]-sumabs[x];
        tmp+=sumabs[N]-sumabs[y];
        chmax(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}
