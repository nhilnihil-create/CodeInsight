#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
#define il inline
#define gc getchar()
#define mp make_pair
#define ri register int
#define rc register char
#define rb register bool
#define rp(i,x,y) for(ri i=x;i<=y;++i)
#define my(i,x,y) for(ri i=x;i>=y;--i)

const int N=1e6+10;
int n,m,d;
string str;

il int read()
{
	rc ch=gc;ri x=0;rb y=1;
	while(ch!='-' && (ch>'9' || ch<'0'))ch=gc;
	if(ch=='-')ch=gc,y=0;
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^'0'),ch=gc;
	return y?x:-x;
}

int main()
{
	n=read();m=read();d=read();str=" RGBY";
	rp(i,0,n-1){rp(j,0,m-1){ri x=(m+i+j)/d%2,y=(m+i-j)/d%2;printf("%c",str[2*x+y+1]);}printf("\n");}
	return 0; 
}
//yjszd!