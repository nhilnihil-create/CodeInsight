#include<bits/stdc++.h>
#define F(i,a,b,c) for(register int i=(a);(b);i=(c))
#define Fu(i,a,b) F(i,(a),i<=(b),i+1)
#define Fd(i,a,b) F(i,(a),i>=(b),i-1)
#define inf 1073741823
#define LL long long
int Fl,ch;template<typename t>int in(t&a){a=0;ch=getchar();Fl=1;while(((ch<'0')||(ch>'9'))&&ch!=EOF)Fl=(ch=='-')?-Fl:Fl,ch=getchar();if(ch==EOF)return 0;while((ch>='0')&&(ch<='9'))a=a*10+ch-'0',ch=getchar();a*=Fl;return 1;}template<typename t,typename ...ARGS>int in(t&a,ARGS&...args){return in(a)+in(args...);}
using namespace std;
LL ans;char c;int n,l,a[200010],b[256];
int main()
{
	c=getchar(); 
	while(!isalpha(c))c=getchar();
	while(isalpha(c))
	{
		++l;
		if(!b[c])a[++n]=c;
		++b[c];
        c=getchar();
	}
	ans=(LL)l*(l-1)/2;
	Fu(i,'a','z')
	ans-=(LL)b[i]*(b[i]-1)/2;
	cout<<ans+1;
	return 0;
}
//BY 线段树蒟蒻

