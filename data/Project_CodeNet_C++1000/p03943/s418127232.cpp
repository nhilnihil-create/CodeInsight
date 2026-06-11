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
	vector<int> a(3);
	cin>>a[0]>>a[1]>>a[2];
	sort(a.begin(), a.end());
	// if(a[0] == a[1] || a[1] == a[2]){
	// 	cout<<"Yes"<<endl;
	// 	return;
	// }
	if(a[0] + a[1] == a[2]){
		cout<<"Yes"<<endl;
		return;
	}
	cout<<"No"<<endl;

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
