#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

typedef long long LL;

#define BITTYPE LL
#define BITCNT  2
#define BITSIZE 512345
namespace _BIT{
    int i=0;
    BITTYPE t[2][BITSIZE];
    inline BITTYPE* get(){
        return t[i++];
    }
}

struct BIT{

    using T=BITTYPE;
    T *t;
    int n;
    
    BIT(int N):t(_BIT::get()),n(N+1){
        REP(i,n+1)t[i]=0;
    }
 
    void add(int r,T v){//add v for [1,r]
        for(;r;r-=r&-r)t[r]+=v;
    }
 
    void add(int l,int r,T v){//add v for [l,r]
        add(r,v);
        add(l-1,-v);
    }
 
    T get(int i){//get sum[i]
        T res=0;
        for(;i<=n;i+=i&-i)res+=t[i];
        return res;
    }
 
};
LL dp[1000001];

LL mod=1000000007;
LL N;
int main(){
        REP(i,1000001){
            dp[i]=0;
        }
	cin>>N;
	if(N==1){
	   cout<<1<<endl;
	   return 0;
	}
	if(N==2){
	   cout<<4<<endl;
	   return 0;
	}
	dp[0]=(N*N)%mod;
	dp[1]=(dp[0]+N*(N-1))%mod;
	LL sum=dp[1];
	sum%=mod;
	LL ans=sum;
	BIT b(N+10);
	b.add(1,N+5,N);	
	b.add(2,N+5,dp[0]);
	REP(i,N-1){
	    if(i==0)continue;
	    if(i==1)continue;
	    ans=b.get(i-1)+dp[i-1]+N*(N-i)+(i-1)*(N-1);
	    ans%=mod;
	    dp[i]=ans;
	    b.add(i+1,N+5,dp[i-1]);
	}
	/*REP(i,3){
	    cout<<dp[i]<<endl;
	}*/
	
        cout<<ans<<endl;
	return(0);
}