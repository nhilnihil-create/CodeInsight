#include<bits/stdc++.h>
#define MAX 100000
#define MOD 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k,s;
	cin>>k>>s;
	int ans = 0;
	for(int i=0;i<=k;++i)
	{
		for(int j=0;j<=k;++j)
		{
			if(i+j>s||s-i-j>k)
				continue;
			++ans;
		}
	}
	cout<<ans<<endl;
	return 0;
}