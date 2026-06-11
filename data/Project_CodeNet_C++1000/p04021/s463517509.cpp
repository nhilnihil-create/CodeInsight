#include<bits/stdc++.h>
#define NMAX 300001
using namespace std;
 
typedef long long ll;
map<ll,ll> pos;
ll v[NMAX],sortedv[NMAX];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll n,i,nr=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>v[i];
        pos[v[i]]=i;
        sortedv[i]=v[i];
    }
    sort(sortedv,sortedv+n);
    for(i=0;i<n;i++){
        if((pos[sortedv[i]]^i)&1)
            nr++;
    }
    cout<<nr/2;
    return 0;
}