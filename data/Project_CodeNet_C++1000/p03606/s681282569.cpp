#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int n,ans;

int main(){
	cin>>n;
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(!i){
			v.push_back({a,b});
		}
		else{
			bool ok=1;
			for(int j=0;j<sz(v);j++){
				if(v[j].first>b || v[j].second<a)continue;
				else{
					v[j].first=min(v[j].first,a);
					v[j].second=max(v[j].second,b);
				}
			}
			if(ok)v.push_back({a,b});
		}
	}
	for(auto i:v){
		ans+=i.second-i.first+1;
	}
	cout<<ans;
	
	
}