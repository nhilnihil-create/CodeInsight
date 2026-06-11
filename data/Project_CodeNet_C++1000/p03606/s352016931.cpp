#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	vector<int> v(100001);
	rep(i,n){
		int l,r; cin>>l>>r;
		for(int j=l; j<=r; j++){
			v[j]++;
		}
	}
	cout<<accumulate(v.begin(),v.end(),0)<<endl;
}