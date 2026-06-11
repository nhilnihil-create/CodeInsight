#include <bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7ll ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	int arr[n] , cnt[n+1];
	memset(cnt , 0 , sizeof(cnt)) ;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i] ;
	cnt[1] = 1 ;
	int last = 1;
	for(int j = 1 ; j < n ; ++j)
	{
		int prv = j-last+1 ;
		cnt[last]++ ;
		if((prv+1)*2-1 > arr[j])
		{
			last++ ;
			cnt[last] = cnt[last-1] - 1 ;
		}
	}
	while(last <= n)
	{
		++last ;
		cnt[last] = cnt[last-1] - 1 ;
	}
	long long ans = cnt[1] ;
	for(int i = 2 ; i <= n ; ++i)
		ans = (ans * 1ll * cnt[i]) % mod ;
	return cout<<ans<<"\n" , 0 ;
}