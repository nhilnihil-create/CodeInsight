#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;

int sig[111111];
int A[111111];
signed main(){
    cin>>N;
    int lat;cin>>lat;
    N--;
    int normal=0;
    rep(i,N){
        char c;
        int a;
        cin>>c>>a;
        if(c=='+')sig[i]=1;
        else sig[i]=-1;
        A[i]=a;
        normal+=a*sig[i];
    }

    int ans=normal;
    int latte=0,malta=0;
    for(int i=N-1;i>=0;i--){
        latte+=A[i];
        normal-=A[i]*sig[i];
        if(sig[i]==-1){
            chmax(ans,normal-latte+malta);
            malta+=latte;
            latte=0;
        }
    }
    cout<<ans+lat<<endl;
    return 0;
}
