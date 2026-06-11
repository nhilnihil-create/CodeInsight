#include <bits/stdc++.h>
#define ll long long
#define INF 1000000000
using namespace std;
string s, chk;
int main()
{
    cin >> s;
    chk = s;
    for (int i = 0 ; i < s.size() / 2 ; ++i )
       swap( s[i], s[ s.size()-1 - i ] );
    for (int i = 0 ; i < s.size() ; ++i)
     switch ( s[i] )
    {
        case 'b' : s[i] = 'd' ; break ;
        case 'd' : s[i] = 'b' ; break ;
        case 'p' : s[i] = 'q' ; break ;
        case 'q' : s[i] = 'p' ; break ;
    } 
    if ( s != chk )
      printf("No\n");
    else
      printf("Yes\n");

    return 0;
}