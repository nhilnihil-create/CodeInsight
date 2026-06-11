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


int solve(){
    int k,s; cin>>k>>s;

    int x=0,y=0,z=0;
    int ans=0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            z = s -i - j ;
            if (z>=0 && z<=k)
            {
                ans++;
            }
            
            
        }
        
    }
    cout<<ans;
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

    

    
	