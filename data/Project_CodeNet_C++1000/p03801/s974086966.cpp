#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	vector< pair<long long , int> >vp ;
	long long ans[n+2] ;
	memset(ans , 0 , sizeof(ans)) ;
	for(int i = 0 ; i < n ; ++i)
	{
		long long x ;
		cin>>x ;
		vp.push_back({x , i}) ;
	}
	vp.push_back({0 , n}) ;
	sort(vp.rbegin() , vp.rend()) ;
	long long prv = -1 ;
	int idx = n ;
	for(int i = 0 ; i < vp.size() ; ++i)
	{
		if(vp[i].first != prv)
		{
			ans[idx] += (prv - vp[i].first) * i ;
			prv = vp[i].first ;
			idx = min(idx , vp[i].second) ;
		}
		else
			idx = min(idx , vp[i].second) ;
	}
	for(int i = 0 ; i < n ; ++i)
		cout<<ans[i]<<"\n";
	return 0 ;
}