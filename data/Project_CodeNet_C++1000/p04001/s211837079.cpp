#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;

int main()
{
    ll n, t, i =0, m ;
    string s ;
    cin >> s ;
    n = s.size()-1;
    ll sum = 0, tmp = 0 ;
    ll subset= pow(2,n);
    for(i=0; i<(1<<n); i++) // like a binary form of n and i ak akta r binary number r representative 
    {
        tmp = 0;
        for(ll j=0 ; j<n ; j++)
        {
            tmp = tmp*10 + s[j] - '0' ;
            if( i & (1<<j) )
            {
                sum+=tmp;
                tmp = 0 ;
            }
        }
        sum+=(tmp*10) + s[n]-'0';
    }
    cout << sum ;
    return 0;
}
