#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int* count = new int[26]();
    for(int i=0;i<s.length();i++)
    {
        count[ s[i] -'a' ]++;
    }
    for(int i=0;i<26;i++)
    {
        if( count[i]%2)
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}