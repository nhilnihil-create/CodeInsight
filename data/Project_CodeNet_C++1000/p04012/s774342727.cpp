#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std ;
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
    cout.tie(0);
    set <char> st ;
    string str ;
    map <char, int> mp ;
    cin >> str ;
    for(int i = 0 ; i < str.size() ; i++)
    {
        if(str[i] >= 'a' && str[i] <='z')
        {
            mp[str[i]]++ ;
            st.insert(str[i]) ;
        }
    }
    int flag = 0 ;
    for(auto i : st)
    {
        //cout << mp[i] << endl ;
        if(mp[i] %2 != 0)
        {
            flag = 1 ;
            break ;
        }
    }
    if(!flag)
    {
        cout <<"Yes\n" ;
    }
     else cout <<"No\n" ;
}
