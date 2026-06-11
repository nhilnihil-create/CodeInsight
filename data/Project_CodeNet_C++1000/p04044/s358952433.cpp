#include<bits/stdc++.h>

#define ll   	long long
#define pb	    push_back
#define F   	first
#define S	    second
#define B   	begin()
#define E	    end()
#define FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


using namespace std ;

int main()
{
    FASTIO ;
    int n , l ;
    cin >> n >> l ;
    vector < string > v(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> v[i] ;
    sort ( v.B , v.E ) ;
    for ( int i = 0 ; i < n ; i++ )
        cout << v[i] ;
    return 0;
}

