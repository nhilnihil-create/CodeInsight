#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s_1="";
    cin>>s;
    s_1+=s[0];
    for(int i=1;i<s.size();i++)
    {
        if(s[i]!=s[i-1])
        s_1+=s[i];
    }
    cout<<s_1.size()-1<<endl;
}