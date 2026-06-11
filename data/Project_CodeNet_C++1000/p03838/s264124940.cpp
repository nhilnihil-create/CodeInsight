#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL x,y;
LL cnt(LL x, LL y){
	if(y<x)return 1e11;
	return y-x;
}

int main(){
	cin>>x>>y;
	LL ans=1e11;
	if(x<y){
		ans=min(cnt(x,y),cnt(-x,y)+1);
		ans=min(ans,cnt(y,-x)+1);
	}else{
		ans=min(cnt(y,x)+2,cnt(-x,y)+1);
		ans=min(ans,cnt(x,-y)+1);
	}
	cout<<ans<<endl;
}