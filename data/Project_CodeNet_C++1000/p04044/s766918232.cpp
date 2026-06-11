#include <bits/stdc++.h>
#define fori(x,y)   for(int i=x;i<y;i++)
using namespace std;




int main() 
{
	#ifndef ONLINE_JUDGE
	freopen("D_IN.txt","r",stdin);
	freopen("D_Out.txt","w",stdout);
	#endif
	
	vector<string> v;
	int n,k;
	cin>>n>>k;
	fori(0,n)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	sort(v.begin(),v.end());

	fori(0,n)
	{
		cout<<v[i];
	}
	
	return 0;
}