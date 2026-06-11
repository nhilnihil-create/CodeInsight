#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n,m,a,b;
	string s,t="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>s;
			if(s=="snuke")
			{
				a=i;
				b=j;
			}
		}
	}
	cout<<t[b]<<a<<endl;
	return 0;
}