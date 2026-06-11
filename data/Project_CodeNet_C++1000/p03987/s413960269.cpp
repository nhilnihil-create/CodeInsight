#include <bits/stdc++.h>

using namespace std ;

const int MAX = 2e5 + 10 ;

long long arr[MAX] , L[MAX] , R[MAX] ;
int n ;

int main()
{
	memset(L , -1 , sizeof(L)) ;
	memset(R , -1 , sizeof(R)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n ;
	for(int i = 0 ; i < n ; ++i)
		cin>>arr[i] ;
	stack<int>s ;
	for(int i = 0 ; i < n ; ++i)
	{
		while(s.size() > 0 && arr[s.top()] > arr[i])
		{
			R[s.top()] = i-1 ;
			s.pop() ;
		}
		if(!s.size())
			L[i] = 0 ;
		else
			L[i] = s.top()+1 ;
		s.push(i) ;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		if(L[i] == -1)
			L[i] = 0 ;
		if(R[i] == -1)
			R[i] = n-1 ;
	}
	long long ans = 0ll ;
	for(int i = 0 ; i < n ; ++i)
	{
		long long x = i - L[i] + 1ll ;
		long long y = R[i] - i + 1ll ;
		ans += x * y * arr[i] ;
	}
	return cout<<ans<<"\n" , 0 ;
}		