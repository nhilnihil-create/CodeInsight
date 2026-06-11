#include <bits/stdc++.h>
using namespace std;
    
int main()  {
    string s;
    cin>>s;
    for(int i=1;i<s.length();i++)
        if(s[i]==s[i-1])
        {
            cout<<i<<" "<<i+1;
            return 0;
        }
    for(int i=2;i<s.length();i++)
        if(s[i-2]==s[i])
        {
            cout<<i-1<<" "<<i+1;
            return 0;
        }
    cout<<"-1 -1";
    return 0;
}