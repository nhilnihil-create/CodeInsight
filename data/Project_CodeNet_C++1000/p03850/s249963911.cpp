#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define rint register int
using namespace std;
inline int read(){int w=1,s=0;char ch=getchar();while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}return w*s;}
ll f[3];int n;
int Fu[1000010];
int main()
{
	memset(f,-0x3f,sizeof(f));
	n=read();n--;
	f[0]=read();
	for(rint i=1;i<=n;++i){char s[2];
		scanf("%s",s+1);int x=read();if(s[1]=='+') Fu[i]=1;
		else Fu[i]=-1;x*=Fu[i];
		f[0]+=x;f[1]-=x;f[2]+=x;
		if(x<0) f[2]=max(f[2],f[1]),f[1]=max(f[0],f[1]);
		f[1]=max(f[1],f[2]);f[0]=max(f[0],f[1]);
	}cout<<f[0];
	return 0;
}