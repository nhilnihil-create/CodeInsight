#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	int n;
	cin>>n;
	int a[n];
	map<int,int> mp;
	rep(i,n){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a,a+n);
	
	int ans=n;
	for(auto itr = mp.begin();itr!=mp.end();++itr){
		if(itr->second >= 3){
			if(itr->second %2 == 0){
				ans-=itr->second-2;
				itr->second=2;
			}
			else {
				ans-=(itr->second-1);
				itr->second = 1;
			}
		}
	}

	int j=0;
	for(int i=0;i<n;i++){
		if(mp[a[i]]==2){
			for(int j=n-1;j>=i;j--){
				if(mp[a[j]]==2){
					mp[a[i]]--;
					mp[a[j]]--;
					ans-=2;
					break;
				}
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
