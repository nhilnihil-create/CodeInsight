//In the name of 'Allah'//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n , x ,i ;
    cin >> n >> x ;
    vector<int> v(n) ;
    for( int i = 0; i < n; i++ )
    {
        cin>> v[i] ;
    }
     ll ans = 0;
     for( int i = 0; i < n-1 ;i++ )
     {
         if(v[i]+v[i+1] > x)
         {
             ans += v[i] + v[i+1] - x;
             v[i+1] -= min(v[i]+v[i+1]-x, v[i+1]);
         }
     }
     cout << ans <<endl;
     return 0;
}
