#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int ans=0;
	rep(i,n-1)
	{
		if(s[i]!=s[i+1]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
