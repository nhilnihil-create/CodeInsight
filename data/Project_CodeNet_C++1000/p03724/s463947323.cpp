#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> g(n);
	for(int i = 0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x]++;
		g[y]++;
	}
	int a = 0;
	for(int i = 0;i<n;i++)
	{
		a+=g[i];
		if(g[i]%2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	//if(a)cout<<"NO"<<endl;
	cout<<"YES"<<endl;
	return 0;
}