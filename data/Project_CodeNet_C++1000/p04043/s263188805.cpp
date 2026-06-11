/**
 *		author:  zvm
 *		created: 02.09.2020 20:00:28
**/

#include <bits/stdc++.h>

using namespace std ;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	vector<int> v(3), good{5,5,7} ;
	for( int i = 0 ; i < 3 ; ++i ) {
		cin >> v[i] ;
	}

	sort(v.begin(),v.end());
	
	cout << ( v == good ? "YES" : "NO" ) << endl ;
}
