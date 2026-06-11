#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	int cnt=0;
	rep(i,n){
		if(i==v[v[i]-1]-1) cnt++;
	}
	cout<<cnt/2<<endl;
}