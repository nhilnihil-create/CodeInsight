#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;
const ll MOD = 1e9+7;

int n;

int dp[N][2];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	ll ans = 0;
	vector<int> v;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x == 0){
			v.push_back(0);
			continue;
		}
		ans += (x-1)/2;
		x -= 2*((x-1)/2);
		v.push_back(x);
	}
	int lst = 0;
	for(int x:v){
		if(lst == 0 && x == 1){
			lst = 1;
			continue;
		}
		if(lst == 0 && x == 2){
			ans++;
			continue;
		}
		if(lst == 1 && x == 1){
			ans++;
			lst = 0;
			continue;
		}
		if(lst == 1 && x == 2){
			ans++;
			continue;
		}
		if(lst == 1 && x == 0){
			lst = 0;
			continue;
		}
	}
	
	cout<<ans;
	
	
	return 0;
}
