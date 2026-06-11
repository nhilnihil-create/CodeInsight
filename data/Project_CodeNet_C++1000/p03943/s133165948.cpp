#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double
#define ff first
#define ss second
ll mod = 1000000007;
ll dp[2][10000000+1];
void fun(){
	vector<int> v(3);
	cin>>v[0]>>v[1]>>v[2];
	sort(v.begin(),v.end());
	if(v[0]+v[1]==v[2]) cout<<"Yes\n";
	else cout<<"No\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1; //cin>>t;
	while(t--){
		fun();
	}
	return 0;
}
