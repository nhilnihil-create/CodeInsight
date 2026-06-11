#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

struct P{
	int d;
	int v;
	bool operator<(const P& opp)const{
		return v<opp.v;
	}
};

void solve(){
	int x;
	cin>>x;
	int sum=0;
	int cnt=1;
	while(sum<x){
		sum+=cnt;
		cnt++;
	}
	int dif=sum-x;
	cout<<cnt-1<<endl;
}

signed main(){
	//while(1)
	solve();
}