#include<bits/stdc++.h>
using namespace std;

#define MAX 302

int n;
int m;
map<int,int> mp;
map<int,int> cnt;
map<int,vector<int> > vec;

int main(){
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		mp[a]++;
		vec[a%m].push_back(a);
	}
	for(auto it:mp){
		cnt[it.first%m]+=it.second;
	}
	for(auto &it:cnt){
		int z=m-it.first;
		z%=m;
		if(z==it.first){
			ans+=it.second/2;
			it.second%=2;
			continue;
		}
		int mz=min(it.second,cnt[z]);
		ans+=mz;
		it.second-=mz;
		cnt[z]-=mz;
		//cout<<it.first<<" "<<mz<<endl;
	}
	for(auto &it:cnt){
		int val=it.first;
		int rest=it.second;
		vector<int> &v=vec[val];
		sort(v.begin(),v.end());
		//cout<<rest<<endl;
		for(int i=0;i+1<v.size();i++){
			if(rest<2)break;
			if(v[i]==v[i+1]){
				//cout<<v[i]<<" "<<v[i+1]<<endl;
				ans++;
				rest-=2;
				i++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
