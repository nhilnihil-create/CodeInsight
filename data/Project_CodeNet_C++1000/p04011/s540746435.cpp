#include<bits/stdc++.h>
 
#define ll long long 
# define skorost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

using namespace std ;
 
ll z , o , ans ;

ll N = 1e4 + 15820 ;

int main(){ skorost ;

	int n , k , x , y ;

	cin >> n >> k >> x >> y ;

	if( n <= k ){

		cout << n * x << endl ;

	}

	else{

		cout << ( k * x ) + ( ( n - k ) * y ) << endl ;

	}

}