#include <bits/stdc++.h>
 
using namespace std ;
 
const int MAX = 5010 ;
 
int dp[MAX][MAX] ;
int arr[MAX] ;
int n , k;
int idx2 ;

bool check(int mid)
{
	if(arr[mid] >= k)
		return 0 ;
	memset(dp , -1 , sizeof(dp)) ;
	bitset<MAX>bit ;
	bit[0] = 1 ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(i == mid || arr[i] >= k)
			continue ;
		bit |= (bit << arr[i]) ;
	}
	for(int i = k-arr[mid] ; i < k ; ++i)
		if(bit[i])
			return 0 ;
	return 1 ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>k ;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i] ;
	sort(arr , arr + n) ;
	int l = 0 , r = n-1 , ans = -1;
	while(l <= r)
	{
		int mid = (l + r) >> 1 ;
		if(check(mid))
			ans = mid , l = mid+1 ;
		else
			r = mid-1 ;
	}
	return cout<<ans+1<<"\n" , 0 ;
}