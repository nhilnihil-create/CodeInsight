#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i,val;
    map<long long, long long> mp;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>val;
        if(mp.find(val)==mp.end())
        {
            mp[val]=1;
        }
        else
        {
            mp.erase(val);
        }
    }
    cout<<mp.size();
    return 0;
}
