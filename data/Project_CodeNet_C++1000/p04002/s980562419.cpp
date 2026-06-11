#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define int long long
#define double long double
#define fre(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
using namespace std;

inline int read(){
	int sum=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}

const int N=100005;
struct node{int x,y;}a[N];
int H,W,n;
map < pair<int,int> ,int> mp;
int f[101];

inline int get(int x,int y){
	return mp.count(make_pair(x,y));
}

inline int getsum(int x,int y){
	int ret=0;
	if(x+2>H||y+2>W) return 0;
	for(int i=x;i<=x+2;i++)
		for(int j=y;j<=y+2;j++) ret+=get(i,j);
	return ret;
}

signed main(){
	H=read();W=read();n=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
	for(int i=1;i<=n;i++) mp[make_pair(a[i].x,a[i].y)]=1;
	for(int i=1;i<=n;i++){
		int x=a[i].x,y=a[i].y;
		for(int i=max((int)1,x-2);i<=x;i++){
			for(int j=max((int)1,y-2);j<=y;j++){
				int ret=getsum(i,j);
				if(ret>0) f[ret]++;
			}
		}
	}
	for(int i=1;i<=9;i++) f[i]/=i;
	int ret=0;
	for(int i=1;i<=9;i++) ret+=f[i];
	f[0]=(H-2)*(W-2)-ret;
	for(int i=0;i<=9;i++) printf("%lld\n",f[i]);
	return 0;
}
