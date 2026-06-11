#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
map<int, int> mp;
int main(){
	IOS
	int n,mn=1e6,mx=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		mp[a]++;
		if(mp[a]==n){
			if(a==n-1||a*2<=n){
				cout<<"Yes";
			}
			else{
				cout<<"No";
			}
			return 0;
		}
		if(a<mn){
			mn=a;
		}
		if(a>mx){
			mx=a;
		}
	}
	if(mp.size()!=2){
		cout<<"No";
		return 0;
	}
	if((mx-mp[mn])*2<=mp[mx]&&mp[mn]<=mn){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}
/*

*/