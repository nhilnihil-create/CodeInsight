#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
	int n,m;
	cin >> n >> m;
	vector<bool> red(n);
	red[0]=true;
	vector<int> in(n,1);
	for(int i =0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		x--;y--;
		if(red[x])red[y] = red[x];
		in[x]--;
		in[y]++;
		if(in[x]==0)red[x]=false;
	}
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		ans += red[i];
	}
	cout<<ans<<endl;
	return 0;
}