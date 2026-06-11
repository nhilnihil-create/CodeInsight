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
int main()
{
    fastRead;
    int n , x;
    cin>>n>>x;
    
    n = 2*n - 1;
    if(x == n || x == 1) {
        cout<<"No\n";
        return 0;
    }
    if( n == 3 && x== 2 ) {
        
        cout<<"Yes\n";
        for(int i =1 ; i <=3 ; i++ ) cout<<i<<'\n';
        return 0;
    }
    vector<int>taken(n+1);
    
    deque<int>dq;
    
    dq.push_back(x);
    dq.push_back(x+1);
    dq.push_front(x-1);
    
    taken[x] = taken[x+1] = taken[x-1] = 1;
    
    int turn = 0;
    
    if(x == n-1) {
        dq.push_back(x-2);
        taken[x-2] =1;
    }
    else {
        dq.push_front(x+2);
        taken[x+2] = 1;
        turn = 1;
    }

    for(int i = 1 ; i<=n ; i++  ) {
        if(taken[i]) continue;
        taken[i] = 1;
        
        if(turn) dq.push_back(i);
        else dq.push_front(i);
        
        turn ^=1;
    }
    
    
    
    cout<<"Yes\n";
    for(auto x : dq) cout<<x<<'\n';
    
    
    
}