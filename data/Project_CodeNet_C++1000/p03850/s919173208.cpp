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

bool sig[111111];
int A[111111];

int dp[111111];

int S[111111];
signed main(){
    cin>>N;
    cin>>dp[0];

    N--;
    rep(i,N){
        char c;
        int a;
        cin>>c>>a;
        sig[i]=c!='+';
        A[i]=a;
        S[i+1]=a;
    }


    rep(i,N)S[i+1]+=S[i];

    int pre=-1,latte=-1001001001001001001ll;
    rep(i,N){
        if(sig[i]&&pre!=-1){
            chmax(latte,dp[pre]-(S[i]-S[pre])-S[i]);
        }
        if(!sig[i]){
            dp[i+1]=max(dp[i],latte+S[i])+A[i];
        }
        else{
            dp[i+1]=max(dp[i]-A[i],latte+S[i]+A[i]);
            pre=i;
        }
    }
    cout<<dp[N]<<endl;
    return 0;
}

