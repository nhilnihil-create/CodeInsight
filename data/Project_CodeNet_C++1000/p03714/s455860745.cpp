#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<long long> a(3*N);
	for(auto &i:a)cin >> i;
	
	priority_queue<long long,vector<long long>,greater<long long>> qx;
	vector<long long> X(N+1);
	X[0]=accumulate(a.begin(),a.begin()+N,0LL);
	for(int i=0;i<N;i++)qx.push(a[i]);
	
	for(int i=0;i<N;i++){
		int k=i+N;
		X[i+1]=X[i]+a[k];
		qx.push(a[k]);
		X[i+1]-=qx.top();
		qx.pop();
	}
	
	reverse(a.begin(),a.end());
	
	priority_queue<long long,vector<long long>,less<long long>> qy;
	vector<long long> Y(N+1);
	Y[0]=accumulate(a.begin(),a.begin()+N,0LL);
	for(int i=0;i<N;i++)qy.push(a[i]);
	
	for(int i=0;i<N;i++){
		int k=i+N;
		Y[i+1]=Y[i]+a[k];
		qy.push(a[k]);
		Y[i+1]-=qy.top();
		qy.pop();
	}
	
	reverse(Y.begin(),Y.end());
	
	long long ans=-999999999999999999;
	for(int i=0;i<N+1;i++)ans=max(ans,X[i]-Y[i]);
	cout << ans << endl;
	return 0;
}