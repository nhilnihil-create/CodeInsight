#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	n++;
	vector<int> v(n); int sum=0;
	for(int i=1; i<n; i++) {cin>>v[i]; sum+=v[i];}
	int m; cin>>m;
	rep(i,m){
		int p,x; cin>>p>>x;
		cout<<sum-(v[p]-x)<<endl;
	}
}