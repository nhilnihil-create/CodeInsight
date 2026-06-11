#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(int i=0; i<n; i++)
#define rep(i,start,n) for(int i=start; i<n; i++)

void solve(){
	
	int n;cin>>n;

	int a[n+1];

	rep(i,1,n+1)cin>>a[i];

	int curr = 1;
	int next = a[curr];
	a[curr]=-1;
	int cnt = 1;

	while( curr!=next && next!=2){
		curr = next;
		if(a[curr]==-1){
			cout<<-1<<endl;
			return;
		}
		next = a[curr];
		a[curr]=-1;
		cnt++;
		// cout<<curr<<" "<<next<<endl;
	}
	if( next==curr ){
		if(curr==2)cout<<cnt<<endl;
		else cout<<-1;
	}
	else cout<<cnt;
	
}
	
signed main(){
    fast;    
    // int t;cin>>t;while(t--)
    solve();    
    return 0;
}
