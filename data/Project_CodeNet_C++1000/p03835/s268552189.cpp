#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int k,s,ans=0;
	cin>>k>>s;
	
	for (int i = 0; i <= k; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			int z = s - i - j;
			if(z>=0 && z<=k){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}