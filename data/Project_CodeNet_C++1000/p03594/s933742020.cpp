#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
typedef std::pair<int,int> P;
#define mk std::make_pair
#define fr first
#define sc second
inline int in()
{
	int k=0;char ch=gt;bool p=1;
	while(ch<'-')ch=gt;if(ch=='-')ch=gt,p=0;
	while(ch>'-')k=k*10+ch-'0',ch=gt;
	return p?k:-k;
}
const int N=4005;
int mp[N][N];char s[5];
int main()
{
	int n=in(),m=in(),k=in();
	s[1]='R',s[2]='Y',s[3]='B',s[4]='G';
	for(int i=1;i<=std::max(n,m)*4;++i)
		for(int j=1;j<=std::max(m,n)*4;++j)
		{
			int x=(i-1)/k+1,y=(j-1)/k+1;
			mp[i][j]=4-(x&1)*2-(y&1);
		}
	for(int i=1;i<=n;++i,puts(""))
		for(int j=1;j<=m;++j)
			putchar(s[mp[i+j+m][i-j+m]]);
	return 0;
}
