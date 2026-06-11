#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,k,x; cin>>n>>k;
	int cnt=0;
	rep(i,n){
		cin>>x;
		cnt+=min(x,abs(k-x));
	}
	cout<<cnt*2<<endl;
}