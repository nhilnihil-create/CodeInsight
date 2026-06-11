#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define ll long long
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
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		if(i+1>a[i+1]){
			int now=i+1;
			while(a[now]==i) now++;
			if((a[i]-i)%2||(now-i-1)%2) puts("First");
			else puts("Second");
			break;
		}
	}
    return 0;
}