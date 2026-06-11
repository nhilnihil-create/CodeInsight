#include <bits/stdc++.h>
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define fr first
#define sc second
using namespace std;
ll ar[26] ;
int main()
{
    ///freopen("input.txt" , "r" , stdin );
    ///freopen("output.txt", "w" , stdout );
    ///Murtazoev_2007
    speed ;
    ///Autor of the greatest code :: Ahmadjon Murtazoev
    string al = "abcdefghijklmnopqrstuvwxyz" ;
    string str ;
    cin >> str ;
    ll a = str.size() ;
    for (ll i = 0 ; i<26 ; i ++ )
    {
        for (ll j = 0 ; j<a ; j ++ )
        {
            if (str[j] == al[i])
            {
                ar[i] ++ ;
            }
        }
    }
    for (ll i = 0 ; i<26 ; i ++ )
    {
        if (ar[i]%2 != 0)
        {
            cout << "No" << endl ;
            return 0 ;
        }
    }
    cout << "Yes" << endl ;
    return 0 ;
}