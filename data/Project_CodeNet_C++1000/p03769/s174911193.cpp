#include<bits/stdc++.h>
using namespace std;

vector<int> solve(long long int x){
	if(x==1)	return vector<int>();
	if(x&1){
		auto res = solve(x-1);
		res.insert(res.begin(),res.size()+1);
		return res;
	}
	else{
		auto res = solve(x>>1);
		res.emplace_back(res.size()+1);
		return res;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int n;
	cin>>n;
	n++;
	auto res = solve(n);
	cout<<res.size()*2<<endl;
	for(int it:res)
		cout<<it<<' ';
	for(int i=1;i<=res.size();i++)
		cout<<i<<' ';
	cout<<endl;
}
