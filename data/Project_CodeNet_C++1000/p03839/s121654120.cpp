#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N,K;
LL A[100010];
LL B[100010];
LL C[100010];
int main(){
	cin>>N>>K;
	LL now=0;
	REP(i,N){
		cin>>A[i];
		if(A[i]>0){
			B[i]=A[i];
			now+=B[i];
		}else{
			C[i]=A[i];
		}
	}
	REP(i,N){
		if(i==0){
			continue;
		}
		B[i]=B[i]+B[i-1];
		C[i]=C[i]+C[i-1];
	}
	/*REP(i,N){
		cout<<B[i]<<" ";
	}
	cout<<endl;
	REP(i,N){
		cout<<C[i]<<" ";
	}
	cout<<endl;*/
	LL ans=0;
	REP(i,N){
		int s=i;
		int e=i+K-1;
		if(e>=N)continue;
		LL b=B[e];
		LL c=C[e];
		if(i!=0){
			b-=B[s-1];
			c-=C[s-1];
		}
		//cout<<b<<" "<<c<<" "<<now<<endl;
		//黒
		ans=max(ans,now+c);
		//白
		ans=max(ans,now-b);
	}
	cout<<ans<<endl;
}