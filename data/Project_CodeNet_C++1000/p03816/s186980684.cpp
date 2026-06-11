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
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> st;
	for(int i=0;i<n;i++){
		cin>>a[i];
		st[a[i]] += 1;
	}
	int cnt1 =0;
	int cnt2 = 0;
	for(auto x:st){
		if(x.Y == 1) continue;
		if(x.Y % 2 == 0){
			cnt1 += 1;
		}
	}
	int ans = st.size();
	if(cnt1%2 == 0){
		cout<<ans<<endl;
	}
	else{
		cout<<ans-1<<endl;
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
