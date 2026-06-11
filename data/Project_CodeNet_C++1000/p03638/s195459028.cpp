#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,h,w,a[N],b[105][105];
int main(){
	cin>>h>>w>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int id=1,s=0,x=1,y=1,d=1;
	while(s<a[id]&&id<=n){
		b[x][y]=id;
		s++;
		if(s==a[id]) s=0,id++;
		if(d==1&&y==w){
			d=-1,x++;
		}
		else if(d==-1&&y==1){
			d=1,x++;
		}
		else y=y+d;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			printf("%d ",b[i][j]);
		} 
	puts("");
	}
	return 0;
}