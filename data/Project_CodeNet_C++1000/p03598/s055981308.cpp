#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	
	int n,k,ans = 0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ans += min(2*x,2*(k-x));
	}
	cout<<ans;
	
	return 0;
}
