#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,l;
	cin>>n>>l;
	vector<int> a(n);
	bool found=false;
	int index;
	for(int i=0;i<n;i++) 
		cin>>a[i];
	for(int i=0;i<n-1;i++)
	{
		if(a[i]+a[i+1] >= l)
		{
			found=true;
			index=i+1;
			break;
		}
	}
	if(found)
	{
		cout<<"Possible\n";
		for(int i=1;i<index;i++)
			cout<<i<<"\n";
		for(int i=n-1;i>=index;i--)
			cout<<i<<"\n";
	}
	else
		cout<<"Impossible\n";
	return 0;
}