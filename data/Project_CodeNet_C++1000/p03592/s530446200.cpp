#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e6+5;
void solve(){
	int n,m,x; 
	cin>>n>>m>>x;
	if(n<m)swap(n,m);/// n is the biggest 
	bool can = false;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			int trt = i*j+(n-i)*(m-j);
			if(trt==x)can = true;
		}
	}
	if(can)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
/// 11000
/// 11000
/// 00111
