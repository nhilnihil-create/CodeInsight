#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL x[100001];
int main(){
	cin>>N;
	REP(i,N){
	    cin>>x[i];
	}
	LL ans=1;
	LL kuuhaku=x[1]-2;
	LL res=2;
	if(x[0]==1&&x[1]==1){
	   ans*=res;
	   kuuhaku++;
	   res--;
	}
	for(int i=2;i<N;i++){
	    kuuhaku=x[i-1]-res;
	    if(kuuhaku>=res-1){
	       res++;
	    }else{
	       ans=(ans*res)%1000000007;
	    }
	}
	while(res>0){
	    ans=(ans*res)%1000000007;
	    res--;
	}
        cout<<ans<<endl;
	return(0);
}