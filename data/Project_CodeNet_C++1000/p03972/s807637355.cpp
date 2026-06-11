#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int H,W;
main()
{
	cin>>H>>W;
	vector<pair<int,bool> >A;
	for(int i=0;i<H+W;i++)
	{
		int a;cin>>a;
		A.push_back(make_pair(a,i<H));
	}
	sort(A.begin(),A.end());
	long ans=0;
	int s=H+W;
	for(int i=0;i<s;i++)
	{
		if(!A[i].second)
		{
			ans+=1L*A[i].first*(H+1);
			W--;
		}
		else
		{
			ans+=1L*A[i].first*(W+1);
			H--;
		}
	}
	cout<<ans<<endl;
}