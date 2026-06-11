#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;


int main(){
	int n,sum=0;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		--x;
		cout<<sum-a[x]+y<<'\n';
	}
}



