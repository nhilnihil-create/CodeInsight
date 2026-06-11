#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int ans;
int query(int x)
{
	printf("? %lld\n",x);
	fflush(stdout);
	char s[3];
	scanf("%s",s);
	if(s[0]=='Y') return 1;
	return 0;
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int ans=1e9;
	int x=query(ans);
	if(x==1)
	{
		while(1)
		{
			ans--;
			int x=query(ans);
			if(x==0)
			{
				printf("! %lld\n",ans+1);
				return 0;
			}
			if(ans==9)
			{
				printf("! %lld\n",1);
				return 0;
			}
			ans++;
			ans/=10;
		}
	}
	while(1)
	{
		ans/=10;
		int x=query(ans);
		if(x==1) break;
	}
	int l=ans+1,r=ans*10-1,res;
	while(l<=r)
	{
		int mid=(l+r)/2;
		int x=query(mid*10);
		if(x==1)
		{
			r=mid-1,res=mid;
		}
		else l=mid+1;
	}
	printf("! %lld\n",res);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

