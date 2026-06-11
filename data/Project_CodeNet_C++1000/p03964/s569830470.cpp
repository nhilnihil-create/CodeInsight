#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<ll,ll> P;

int main()
{
	int n;
	cin>>n;
	vector<P> vi;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		vi.push_back(P(a,b));
	}
	for(int i=1;i<n;i++)
	{
		if(vi[i].first<vi[i-1].first||vi[i].second<vi[i-1].second)
		{
			ll ri = max(vi[i-1].first,vi[i-1].second);
			ll le = 1;
			ll mid;
			while(le+1<ri)
			{
				mid = (ri+le)/2;
				ll mi = (vi[i-1].first+vi[i].first-1)/vi[i].first;
				ll ma = (vi[i-1].second+vi[i].second-1)/vi[i].second;
				if( mid>=mi && mid>= ma )
				{
					ri = mid;
				}
				else
				{
					le = mid;
				}
			}
			vi[i].first*=ri;
			vi[i].second*=ri;
		}
	}
	cout<<vi[n-1].first+vi[n-1].second<<endl;
}
