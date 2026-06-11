// copied
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 100005
using namespace std;
inline int in(){
    int x=0;bool f=0; char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
int sums[MN],sumt[MN];
int a,b,c,d,q,ls,lt,res1,res2;
char s[MN],t[MN];
int main()
{
	scanf("%s%s",s,t);q=in();
	ls=strlen(s);lt=strlen(t);
	for (int i=1;i<=ls;++i)
	sums[i]=sums[i-1]+1+(s[i-1]=='B');
	for (int i=1;i<=lt;++i)
	sumt[i]=sumt[i-1]+1+(t[i-1]=='B');
	for (int i=1;i<=q;++i){
		a=in();b=in();c=in();d=in();
		res1=sums[b]-sums[a-1];
		res2=sumt[d]-sumt[c-1];
		if ((res1%3)==(res2%3)) puts("YES");else puts("NO");
	} return 0;
}
