#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	int h,w,n,a;
	vector<int>v;
	cin>>h>>w;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		for(int j=0;j<a;j++)
		{
			v.push_back(i);
		}
	}
	for(int i=1;i<=h;i++)
	{
		if((i-1)%2)
		{	
			for(int j=w*i-1;j>=w*(i-1);j--)
			{
				if(j==w*i-1)cout<<v[j];
				else cout<<" "<<v[j];
			}
		}	
		else
		{	
			for(int j=w*(i-1);j<w*i;j++)
			{
				if(j==w*(i-1))cout<<v[j];
				else cout<<" "<<v[j];
			}
		}
		cout<<endl;
	}
	return 0;
}