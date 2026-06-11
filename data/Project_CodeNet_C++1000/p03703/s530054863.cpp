/*
luogu AT2581
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lowbit(x) (x&-x)

int n,k,s[200005];
int ans,c[200005];
vector<int> v;

void lsh()
{
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}

void fix(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
		c[i] += v;
}

int ask(int x)
{
	int res=0;
	for(int i=x;i>=1;i-=lowbit(i))
		res += c[i];
	return res;
}

signed main()
{
	cin>>n>>k;
	for(int i=1,x;i<=n&&cin>>x;i++)
	{
		s[i] = s[i-1]+x;
		v.push_back(s[i]-k*i);
	}
	lsh();
	fix(lower_bound(v.begin(),v.end(),0)-v.begin()+1,1);
	for(int r=1;r<=n;r++)
	{
		int u=lower_bound(v.begin(),v.end(),s[r]-k*r)-v.begin()+1;
		ans += ask(u);
		fix(u,1);
	}
	cout<<ans<<endl;
	
	return 0;
}