#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t,n;
	cin>>t>>n;
	int ar[t];
	for(int i=0;i<t;++i) cin>>ar[i];
	sort(ar,ar+t,greater<int>());
	int sum=0;
	for(int i=0;i<n;++i) sum+=ar[i];
	cout<<sum;
	return 0;
}
