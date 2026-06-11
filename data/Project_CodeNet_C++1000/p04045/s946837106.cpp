#include<bits/stdc++.h>

#define ll   	long long
#define pb	    push_back
#define F   	first
#define S	    second
#define B   	begin()
#define E	    end()
#define FASTIO   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


using namespace std ;
map < int , bool > d ;
inline bool is_ok ( int x )
{
    while ( x )
    {
        if ( d[x%10] )
            return 0 ;
        x /= 10 ;
    }
    return 1 ;
}
int main()
{
    FASTIO ;
    int n , k ;
    cin >> n >> k ;
    for ( int i = 0 ; i < k ; i++ )
    {
        int x ;
        cin >> x ;
        d[x] = 1 ;
    }
    while ( !is_ok(n) )
        n++;
    cout << n ;
    return 0;
}

