#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

void solve(){
	int h,w;
	cin>>h>>w;
	vector<string> c(h+1);
	for(int i=1;i<=h;i++){
		cin>>c[i];
		c[i] = " "+c[i];
	}
	for(int i=1;i<=2*h;i++){
		for(int j=1;j<=w;j++){
			cout<<c[(i+1)/2][j];
		}
		cout<<endl;
	}
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
