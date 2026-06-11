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
    int a[3];
    cin >> a[0] >> a[1] >> a[2] ;
    int x = 0 , y = 0 ;
    for ( int i = 0 ; i < 3 ; i++ )
    {
        if ( a[i] == 5 ) x++ ;
        else if ( a[i] == 7 ) y++ ;
    }
    cout << ( x == 2 && y == 1 ? "YES" : "NO" ) ;
    return 0;
}

