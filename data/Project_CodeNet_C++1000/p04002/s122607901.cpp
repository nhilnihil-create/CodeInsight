#include<bits/stdc++.h>
#define int long long
#define rg register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
const int N=200000+10;
const int mod=1e9+7;
const int inf=1e10;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return f*x;
}
int X[N],Y[N],W,H,n,res;
map<int,int> Map,f;
void calc(int x,int y){
	int X1,Y1,X2,Y2;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			if(i==1&&j==1) X1=x-2,Y1=y-2,X2=x,Y2=y;
			if(i==1&&j==2) X1=x,Y1=y-2,X2=x+2,Y2=y;
			if(i==1&&j==3) X1=x-1,Y1=y-2,X2=x+1,Y2=y;
			if(i==2&&j==1) X1=x-2,Y1=y,X2=x,Y2=y+2;
			if(i==2&&j==2) X1=x,Y1=y,X2=x+2,Y2=y+2;
			if(i==2&&j==3) X1=x-1,Y1=y,X2=x+1,Y2=y+2;
			if(i==3&&j==1) X1=x-2,Y1=y-1,X2=x,Y2=y+1;
			if(i==3&&j==2) X1=x,Y1=y-1,X2=x+2,Y2=y+1;
			if(i==3&&j==3) X1=x-1,Y1=y-1,X2=x+1,Y2=y+1;
			if(X1<1||Y1<1||X2>H||Y2>W) continue;
			if(f[X1*inf+Y1]) continue;
			f[X1*inf+Y1]=1;
			int ans=0;
			res++;
			for(int i=X1;i<=X2;i++)
				for(int j=Y1;j<=Y2;j++)
					if(Map[i*inf+j])
						ans++;
			//		if(ans==0) cout<<x<<" "<<y<<" "<<X1<<" "<<Y1<<" "<<X2<<" "<<Y2<<endl;
			f[ans]++;
		}
}
main(){
	H=read(),W=read(),n=read();
	for(int i=1;i<=n;i++)
		X[i]=read(),Y[i]=read(),Map[X[i]*inf+Y[i]]=1;
	for(int i=1;i<=n;i++)
		calc(X[i],Y[i]);
	cout<<(H-2)*(W-2)-res<<endl;
	for(int i=1;i<=9;i++)
		cout<<f[i]<<endl;
}
