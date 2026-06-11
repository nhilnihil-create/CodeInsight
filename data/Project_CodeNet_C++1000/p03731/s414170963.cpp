#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,t; cin>>n>>t;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	ll sec=t;
	for(int i=1; i<n; i++){
		if(v[i]-v[i-1]<t) sec+=v[i]-v[i-1];
		else sec+=t;
	}
	cout<<sec<<endl;
}