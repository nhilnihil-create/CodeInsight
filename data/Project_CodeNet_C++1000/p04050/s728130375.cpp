#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> a(m);
	int cnt = 0;
	for(int i = 0; i < m; i++){
		cin>>a[i];
		if(a[i]&1)cnt++;
	}
	if(cnt > 2){
		cout<<"Impossible"<<'\n';
		exit(0);
	}
	if(m == 1){
		if(a[0] == 1){
			cout<<"1\n1\n1\n";
		}else{
			cout<<a[0]<<'\n';
			cout<<2<<'\n';
			cout<<a[0] - 1<<" "<<1<<'\n';
		}
	}else if(m == 2){
		sort(a.begin(), a.end());
		for(auto x : a){
			cout<<x<<" ";
		}
		cout<<'\n';
		if(a[0] == 1){
			cout<<1<<'\n';
			cout<<a[1] + 1<<'\n';
		}else{
			cout<<2<<'\n';
			cout<<a[0] - 1<<" "<<a[1] + 1<<'\n';
		}
	}else{
		vector<int> od, ev;
		for(auto x : a){
			if(x&1)od.push_back(x);
			else ev.push_back(x);
		}
		vector<int> ans;
		if(od.size())ans.push_back(od[0]);
		for(auto x : ev){
			ans.push_back(x);
		}
		if(od.size() > 1)ans.push_back(od[1]);
		for(auto x : ans){
			cout<<x<<" ";
		}
		cout<<'\n';
		ans[0] += 1;
		ans.back() -= 1;
		if(!ans.back())ans.pop_back();
		cout<<ans.size()<<'\n';
		for(auto x : ans){
			cout<<x<<" ";
		}
		cout<<'\n';
	}

	return 0;
}