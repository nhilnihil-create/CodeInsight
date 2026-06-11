#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sum=0;
	vector<int> a;
	for(int i=0;i<n;i++) 
	{
		int x;
		cin>>x;
		if(x%10) a.push_back(x);
		sum+=x;
	}
	if(sum%10)
	{
		cout<<sum;
		return 0;
	}
	if(a.size()==0)
	{
		cout<<0;
		return 0;
	}
	sort(a.begin(),a.end());
	cout<<sum-a[0];
	return 0;
}
