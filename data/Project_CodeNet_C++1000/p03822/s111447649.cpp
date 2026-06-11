#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
int n;
vector<int> win[100009];
int getdep(int x){
	vector<int> dps;
	if(win[x].size()==0)return 0;
	for(int i=0;i<win[x].size();i++){
		dps.pb( getdep(win[x][i]) );
	}
	sort(dps.begin(), dps.end() );
	for(int i=0;i<dps.size();i++){
		dps[i] += dps.size() - i;
	}
	sort(dps.begin(),dps.end());
	return dps[dps.size()-1];
}
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		int tmp;
		cin>>tmp;
		win[ tmp ].pb(i);
	}
	cout<<getdep(1)<<endl;
	return 0;
}