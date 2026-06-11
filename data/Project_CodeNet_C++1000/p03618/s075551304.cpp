#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n=s.length();
    ll z[26];
    for(int i=0;i<26;i++)
    z[i]=0;
    for(int i=0;i<n;i++)
    {
        z[s[i]-'a']++;
    }
    ll ans=0;
    for(int i=0;i<26;i++)
    {
        ll q=(z[i]*z[i])-z[i];
        ans=ans+q/2;
    }
    cout<<1+(n*(n-1))/2-ans<<endl;
}