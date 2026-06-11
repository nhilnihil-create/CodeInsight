#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rall(x) (x).rbegin(),(x).rend()

int main(){
	int n,k; cin>>n>>k;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(rall(v));
	int ans=0;
	rep(i,k) ans+=v[i];
	cout<<ans<<endl;	
}