#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;

bool check(string s)
{
    if(s.length()%2!=0)
        return false;
    ll m=s.length()/2;
    string s1,s2;
    for(int i=0;i<m;i++)
        s1+=s[i];
    for(int i=m;i<s.length();i++)
        s2+=s[i];
    if(s1==s2)
        return true;
    else
        return false;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    ll x=s.length();
    while(x--)
    {
        s=s.substr(0,s.length()-1);
        if(check(s)==true)
        {
            cout<<s.length()<<endl;
            return 0;
        }
    }
}