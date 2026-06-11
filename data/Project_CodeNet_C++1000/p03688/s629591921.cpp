#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define int long long
#define hh puts("")
#define pc putchar
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
using namespace std;
const int N=100005;
int n,a[N];
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
void write(int x){if(x<0){x=-x,pc('-');}if(x>9) write(x/10);pc(x%10+48);}
void writeln(int x){write(x),hh;}
void writesp(int x){write(x),pc(' ');}
signed main(){
	n=read();
	int mx=0,mn=1e9;
	for(int i=1;i<=n;i++){
		a[i]=read();
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx-mn>1) puts("No");
	else if(mx==mn){
		if(mx<=n/2||mx==n-1) puts("Yes");
		else puts("No");
	}
	else{
		int c1=0,c2=0;
		for(int i=1;i<=n;i++){
			c1+=(a[i]==mn);
			c2+=(a[i]==mx);
		}
		if(mx-c1>=1&&mx-c1<=c2/2) puts("Yes");
		else puts("No");
	}
	return 0;
}