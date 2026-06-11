#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int n , m ;

long long ans = 0ll ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>m ;
	vector< pair<long long , int> >vp ;
	for(int i = 0 ; i < n ; ++i)
	{
		long long x ;
		cin>>x ;
		vp.push_back({x , 0}) ;
	}
	for(int i = 0 ; i < m ; ++i)
	{
		long long x ;
		cin>>x ;
		vp.push_back({x , 1}) ;
	}
	n++,m++;
	sort(vp.begin() , vp.end()) ;
	for(int i = 0 ; i < vp.size() && n && m ; ++i)
	{
		if(vp[i].second == 0)
			ans += m*1ll*vp[i].first , n-- ;
		else
			ans += n*1ll*vp[i].first , m-- ;
	}
	return cout<<ans<<"\n" , 0 ;
}		