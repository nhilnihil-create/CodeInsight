#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Y cout << "YES\n"
#define N cout << "NO\n"
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define R(i,n) for(int i = 0 ; i < n ; i++)

int main()
{
    ll n , l , a[100010] , ans = 0 , max = 0 , b ;
    cin >> n >> l ;
    R(i,n)
    {
        cin >> a[i] ;
        if(i != 0)
        {
            if(max < (a[i] + a[i-1]))
            {
                max = (a[i] + a[i-1]) ;
                b = i ;
            }
        }
    }
    if(max < l)
    {
        cout << "Impossible\n" ;
    }
    else
    {
        cout << "Possible\n" ;
        for(int i = 1 ; i < b ; i++)
        {
            cout << i << endl ;
        }
        for(int i = n - 1 ; i > b ; i--)
        {
            cout << i << endl ;
        }
        cout << b << endl ;
    }
}