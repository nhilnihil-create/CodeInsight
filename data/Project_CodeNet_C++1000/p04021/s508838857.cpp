#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

int n;
vector<ii> v;
int main(){
	cin>>n;
	
	for (int x=0;x<n;x++){
		v.push_back(ii(-1,x));
		cin>>v.back().first;
	}
	
	sort(v.begin(),v.end());
	
	int ans=0;
	for (int x=0;x<n;x+=2){
		if (v[x].second&1) ans++;
	}
	
	cout<<ans;
}