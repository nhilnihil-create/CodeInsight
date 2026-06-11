#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int>d;
int w[100],v[100],N,W;
int dp(int i,int j){
	pair<int,int> p=make_pair(i,j);
	if(d.count(p)) return d[p];
	long res;
	if(i==N)res=0;
	else if(j<w[i])res=dp(i+1,j);
	else res=max(dp(i+1,j),dp(i+1,j-w[i])+v[i]);
	return d[p]=res;
}
int main(){
	cin>>N>>W;
	for(int i=0;i<N;i++)cin>>w[i]>>v[i];
	cout<<dp(0,W)<<endl;
}
