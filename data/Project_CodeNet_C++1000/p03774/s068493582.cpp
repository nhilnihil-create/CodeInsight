#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
struct p{
	int x,y;
}a[N],b[N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y;
	for(int i=1;i<=n;i++){
		int id=0,mx=1e9,x=-1;
		for(int j=1;j<=m;j++){
			int tmp=abs(a[i].x-b[j].x)+abs(a[i].y-b[j].y);
			if(mx>tmp){
				mx=tmp,id=j,x=b[j].x;
			}
			else if(mx==tmp&&b[j].x<x) x=b[j].x,id=j; 
		}
		printf("%d\n",id);
	}
	return 0;
}