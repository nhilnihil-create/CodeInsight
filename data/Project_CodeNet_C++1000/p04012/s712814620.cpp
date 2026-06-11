#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define ff first
#define ss second
#define p pair<int,int>
#define pb push_back
#define endl '\n'
#define w(t) ll test;cin>>test;while(test--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi acos(-1)

int main()
{
    fast;
    string s;
    map<char,int>mp;
    cin>>s;
    for(auto i:s)
    {
        mp[i]++;
    }
    int flag=1;
    for(auto i:mp)
    {
        if(i.ss&1)flag=0;
    }
    cout<<(flag?"Yes":"No")<<endl;

}

