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
    
    vector<ll>vec(n+1) ;
    ll ans = 0;
    for(int i = 0 ; i < n ; i++ ) {
        cin>>vec[i];
    }
    
    ll sum = 0;
    
    for(int i =0 ; i <=n ; i++ ) {
        
        if(vec[i] == 0 ) {
            ans += sum/2;
            sum = 0;
        }
        else sum += vec[i];
    }
    
    cout<<ans<<'\n';
    return 0;
    
}