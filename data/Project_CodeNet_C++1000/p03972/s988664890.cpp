#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int H,W;
main()
{
	cin>>H>>W;
	vector<pair<int,pair<int,bool> > >A;
	for(int i=0;i<H+W;i++)
	{
		int a;cin>>a;
		A.push_back(make_pair(a,make_pair(i<H?H:W,i<H)));
	}
	sort(A.begin(),A.end());
	long ans=0;
	int h=H,w=W;
	for(int i=0;i<H+W;i++)
	{
		if(!A[i].second.second)
		{
			ans+=1L*A[i].first*(h+1);
			w--;
		}
		else
		{
			ans+=1L*A[i].first*(w+1);
			h--;
		}
	}
	cout<<ans<<endl;
}