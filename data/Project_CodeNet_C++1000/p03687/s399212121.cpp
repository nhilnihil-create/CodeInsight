#include<bits/stdc++.h>
using namespace std;

bool condition( string s)
{
    char t = s[0];
    for(int i=0;i<s.length();i++)
    {
        if( s[i] != t)
            return false;
    }
    return true;
}
int val ( string s , char a)
{
    int ans =0;
    while( !condition(s ) )
    {
        string temp;
        for(int i=0;i<s.length() -1 ;i++)
        {
            if( s[i] == a || s[i+1] == a )
            {
                temp.push_back(a);
            }
            else temp.push_back( s[i] );
        }
        ans++;
        s = temp;
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int ans = INT_MAX ;
    for(int i=0;i<26;i++)
    {
        int temp  = val( s , 'a' + i);
        ans = min( ans , temp);
    }
    cout<<ans;

}