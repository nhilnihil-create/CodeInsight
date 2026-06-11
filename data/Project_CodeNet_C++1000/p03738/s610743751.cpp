#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fast_in_out  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
int main()
{
    fast_in_out;
    string s1,s2;
    cin >> s1 >> s2;
    if(s1.size() == s2.size())
    {
        if(s1 > s2)
        {
            cout << "GREATER";
        }
        else if(s1 < s2)
        {
            cout << "LESS";
        }
        else
        {
            cout << "EQUAL";
        }
    }
    else if(s1.size() > s2.size())
    {
        cout << "GREATER";
    }
    else
    {
        cout << "LESS";
    }
}