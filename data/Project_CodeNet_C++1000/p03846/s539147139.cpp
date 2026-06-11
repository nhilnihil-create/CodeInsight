#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


typedef tree<int,null_type,less<int>,rb_tree_tag,
		tree_order_statistics_node_update> indexed_set;
#define P pair<int,int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define st std::string 
#define pb push_back 
#define ll long long 
#define pq(x) std::priority_queue<x> 
#define ultapq(x) priority_queue<x,vector<x>,greater<x>> 
#define show_pq(x,n) for(int i = 0; i < n; i++){cout<<x.top(); x.pop();} 
#define itrt(yo) for(auto x:yo){std::cout<<x<<" ";} 
#define vec(x) std::vector<x> 
#define nl '\n' 
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define ALL(x) x.begin(),x.end() 
#define just int i= 0; i<n ; i++

const int MOD = 1e9+7;


ll binpow( ll a, ll b) {
    a %= MOD;
    ll res = 1;
    while (b>0)
    {
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b = b>>1; 
    }
    return res;    
}

int solve(){
    ll n; cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = abs( i-(n-i-1));
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" "<<nl;
    // }
    ll b[n];
    for(just){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);

    for (int i = 0; i < n; i++)
    {
        if (a[i]!=b[i])
        {
            cout<<0;
            return 0;
        }
    }

   
    
       
        
        
    
        ll ui = binpow(2,n/2);
        cout<<ui%MOD;
    
    return 0;
    
    
    
    
    
}

int main()
{
    IOS;
    int t=1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    
}

    

    
	