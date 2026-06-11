#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0;i<n;i++)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> first(n+1), last(n+1);
	rep(i,m) {
		int x,y;
		cin>>x>>y;
		if(x==1)first[y]=1;
		if(x==n)last[y]=1;
		if(y==1)first[x]=1;
		if(y==n)last[x]=1;
	}
	rep(i,n-2){
		if(first[i+2]&&last[i+2]){
			cout<<"POSSIBLE"<<endl;
			return 0;
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}