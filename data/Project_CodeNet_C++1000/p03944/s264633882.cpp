#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int main(){
	int w,h,n;
	cin>>w>>h>>n;
	int x1=0,x2=w,y1=0,y2=h;
	for(int i=1;i<=n;i++){
		int x,y,a;
		cin>>x>>y>>a;
		if(a==1)
			x1=max(x1,x);
		else if(a==2)
			x2=min(x2,x);
		else if(a==3)
			y1=max(y1,y);
		else if(a==4) 
			y2=min(y2,y);
	}
	if(x1>=x2||y1>=y2) puts("0");
	else printf("%d\n",(x2-x1)*(y2-y1));
	return 0;
}