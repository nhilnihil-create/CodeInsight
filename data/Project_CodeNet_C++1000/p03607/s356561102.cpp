#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int c=0;
	unordered_map<int,int> paper;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		paper[x]++;
	}
	for(auto it:paper)
	{
		if(it.second&1) 
			c++;
	}
	cout<<c;
	return 0;
}
