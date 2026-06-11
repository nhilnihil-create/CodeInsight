#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    int *a =  new int[26]();
    for(int i=0;i<s.length();i++)
    {
        if( a[s[i] -'a' ] != 0)
        {
            cout<<"no";
            return 0;
        }
        a[s[i]-'a']++;
    }
    cout<<"yes";
}
