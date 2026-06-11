//https://www.facebook.com/profile.php?id=100015484067230
//In the name of 'ALLAH'
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string s ;
    cin >> s ;
    map< char , ll > mp ;

    for( ll i = 0 ; i < s.size() ; i++ )
    {
        mp[s[i]]++;
    }

    for( auto u  : mp )
    {
        if( u.second%2!=0 )
        {
            cout<<"No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}
