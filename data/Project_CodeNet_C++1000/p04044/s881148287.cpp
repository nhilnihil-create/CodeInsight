#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
ll n,l;
cin>>n>>l;
string s[n];
for(int i=0;i<n;i++)
{

    cin>>s[i];
}
sort(s,s+n);
for(auto i: s)cout<<i;
    
}