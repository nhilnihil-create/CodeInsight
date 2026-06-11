#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;
LL a[8];
int main(){
	REP(i,7){
		cin>>a[i];
	}
	LL ans=0;
	ans+=a[1]*2;
	ans+=(a[3]/2)*4;
	ans+=(a[4]/2)*4;
	ans+=(a[0]/2)*4;
	LL ans2=0;
	ans2+=a[1]*2;
	if(a[3]>0&&a[4]>0&&a[0]>0){
		a[3]--;
		a[4]--;
		a[0]--;
		ans2+=6;
	}
	ans2+=(a[3]/2)*4;
	ans2+=(a[4]/2)*4;
	ans2+=(a[0]/2)*4;
	cout<<max(ans,ans2)/2<<endl;
}