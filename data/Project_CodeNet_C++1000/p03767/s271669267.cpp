#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
#define all(x) (x).begin(),(x).end()

int main(){
	int n; cin>>n; n*=3;
	vector<int> v(n);
	rep(i,n) cin>>v[i];
	sort(all(v));
	ll cnt=0;
	for(int i=n-2; i>=n/3; i-=2){
		cnt+=v[i];
	}
	cout<<cnt<<endl;
}