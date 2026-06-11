#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int a,b,c;
	cin>>a>>b>>c;
	unordered_map<int,int> found;
	int mul=a;
	while(true)
	{
		int md=mul%b;
		if(found.find(md)!=found.end())
		{
			cout<<"NO";
			return 0;
		}
		if(md==c)
		{
			cout<<"YES";
			return 0;
		}
		mul+=a;
		found[md]=1;
	}
	return 0;
}