#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 1000000007
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

main()
{   FAST;
    int t,n,c=0,k;
    cin>>t;
    map<int,int>mp;
    for(int i=0;i<t;i++){
        cin>>k;
        mp[k]++;
    }
    for(auto it:mp){
        if(it.second &1) c++;
    }
    cout<<c;
}