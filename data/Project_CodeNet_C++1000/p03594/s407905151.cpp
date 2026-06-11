#include<bits/stdc++.h>
#define ts cout<<"ok"<<endl
#define ll long long
#define hh puts("")
using namespace std;
int n,m,d;
char s[]={'R','Y','G','B'};
inline int read(){
    int ret=0,ff=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') ff=-ff;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+(ch^48);ch=getchar();}
    return ret*ff;
}
signed main(){
	n=read(),m=read(),d=read();
	for(int i=1;i<=n;i++,hh)
		for(int j=1;j<=m;j++){
			int tx=i+j+1e5,ty=i-j+1e5;
			printf("%c",s[((tx/d)&1)*2+((ty/d)&1)]);
		}
    return 0;
}