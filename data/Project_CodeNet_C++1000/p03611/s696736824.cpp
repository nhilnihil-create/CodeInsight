#include<bits/stdc++.h>
using namespace std;
int main(){
	
	int n;cin>>n;
	int a[n];
	map<int,int>mp;
	for(int i = 0; i < n; ++i){cin>>a[i];mp[a[i]]++;}
	
	int ans = 0;

	for(int i=-1;i<1e5;i++){

		int cnt = mp[i] + mp[i+1] + mp[i-1];

		ans = max(ans,cnt);

	}

	cout<<ans<<endl;

	return 0;

}