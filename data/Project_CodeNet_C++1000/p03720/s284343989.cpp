#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	n++;
	vector<int> v(n);
	rep(i,m){
		int a,b; cin>>a>>b;
		v[a]++; v[b]++;
	}
	for(int i=1; i<n; i++) cout<<v[i]<<endl;
}