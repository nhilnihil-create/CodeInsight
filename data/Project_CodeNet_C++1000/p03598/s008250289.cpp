#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	int n, k; cin>>n>>k;
	int ans = 0;
	vector< int > v(n);
	for(int &i : v){
		cin>>i;
		ans += min(2 * abs(k - i), 2 * i);
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

