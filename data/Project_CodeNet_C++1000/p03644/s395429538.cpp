#include<bits/stdc++.h>
using namespace std;

#define ll long long

typedef pair< int, int > ii;
typedef vector< ii > vii;

void solve(){
	int n; cin>>n;
	int ans = 1;
	while(n / 2){
		n /= 2;
		ans *= 2;
	}
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

