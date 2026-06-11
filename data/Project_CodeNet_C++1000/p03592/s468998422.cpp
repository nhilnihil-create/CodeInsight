#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long 
signed main() 
{
    IOS;    
    int n,m,k;
    cin>>n>>m>>k;
    set<int>st;
    for(int x=0;x<=n;x++){
    	for(int y=0;y<=m;y++){
    		st.insert(m*x+n*y-2*x*y);
    	}
    }
    if(st.count(k)>0)cout<<"Yes";
    else cout<<"No";
    return 0; 
} 
