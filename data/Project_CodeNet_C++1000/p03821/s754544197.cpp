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
ll a[MAX] , b[MAX];

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) cin>>a[i]>>b[i];
    
    ll ans = 0;
    
    for(int i = n-1 ; i >=0 ; i-- ) {
        
        a[i] += ans;
        
        int rem = a[i]%b[i];
        
        if(rem == 0 ) continue;
        
        ans += b[i] - rem;
    }
    
    cout<<ans<<'\n';
    return 0;
    
}