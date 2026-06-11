#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,a;
	cin>>n;
	vector<int>v(n+1);
	for(int i=0;i<n;i++){
		cin>>a;
		v[i]=a;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		if(v[v[i]-1]==i+1){;
		cnt++;
		}
	}
	cout<<cnt/2<<endl;
	return 0;
}
