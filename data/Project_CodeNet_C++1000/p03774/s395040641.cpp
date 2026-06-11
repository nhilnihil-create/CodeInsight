#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	vector<pair<int,int>> vp(n);
	rep(i,n){
		cin>>vp[i].first>>vp[i].second;
	}
	vector<pair<int,int>> pp(m);
	rep(i,m){
		cin>>pp[i].first>>pp[i].second;
	}
	//for(auto x:pp) cout<<x.first<<" "<<x.second<<endl;
	
	vector<int> a(m);
	rep(i,n){
		rep(j,m){
			a[j]=abs(vp[i].first-pp[j].first)+abs(vp[i].second-pp[j].second);
		}
		//for(auto x:a) {cout<<x;} cout<<endl;
		int itmn=min_element(a.begin(),a.end())-a.begin();
		cout<<itmn+1<<endl;
	}
}