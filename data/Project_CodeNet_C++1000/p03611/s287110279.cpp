#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int r=100001;
	int n; cin>>n;
	vector<int> v(r);
	rep(i,n){
		int a; cin>>a; v[a]++;
	}
	int mx=0;
	for(int i=1; i<r-1; i++){
		int sum=v[i-1]+v[i]+v[i+1];
		mx=max(mx,sum);
	}
	cout<<mx<<endl;
}