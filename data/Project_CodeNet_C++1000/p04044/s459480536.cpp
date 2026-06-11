#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(),(x).end()

int main(){
	int n,m; cin>>n>>m;
	vector<string> v(n);
	rep(i,n) cin>>v[i];
	sort(all(v));
	for(auto x:v) cout<<x;
}