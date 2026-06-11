#include <bits/stdc++.h>

using namespace std ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin>>n ;
	int x , place[n] ;
	for(int i = 0 ; i < n ; ++i)
	{
		cin>>x ;
		x-- ;
		place[x] = i ;
	}
	for(int i = 0 ; i < n ; ++i)
		cout<<40000 * (i+1)<<" " ;
	cout<<"\n" ;
	for(int i = 0 ; i < n ; ++i)
		cout<<40000 * (n-i) + place[i]<<" " ;
	return 0 ;
}