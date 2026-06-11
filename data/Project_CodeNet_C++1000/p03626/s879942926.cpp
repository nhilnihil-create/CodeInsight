#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
const long long md=1000000007;
string s1,s2;
int n,p;
bool ok;
long long ans;
int main()
{
	cin>>n>>s1>>s2;
	if(s1[0]==s2[0])
	{
		ans=3;
		p++;
		ok=true;
	}
	else
	{
		ans=6;
		p+=2;
		ok=false;
	}
	while(p<n)
	{
		if(s1[p]==s2[p])
		{
			if(ok)
			{
				ans*=2;
			}
			p++;
			ok=true;
		}
		else
		{
			if(ok)
			{
				ans*=2;
			}
			else
			{
				ans*=3;
			}
			p+=2;
			ok=false;
		}
		ans%=md;
	}
	cout<<ans<<endl;
	return 0;
}