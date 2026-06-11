#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int n;

int main()
{
    fastRead;
    int n;
    cin>>n;
    
    vector<int>vec(n) , v1 , v2 , tmp;
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    tmp = vec;
    sort(tmp.begin() , tmp.end());
    
    map<int,int>mp;
    for(int i =0 ; i < n ; i+=2) {
        mp[tmp[i]] = 1;
    }
    int ans = 0;
    for(int i = 1 ; i < n ; i+=2 ) {
        if(mp[vec[i]]) ans++;
    }
    
    cout<<ans<<'\n';
    return 0;
    
    
}