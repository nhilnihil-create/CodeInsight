#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	vector<int> v;
	while(n--) {
		int x;
		cin>>x;
		v.emplace_back(x);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int m=0;
	for(int i=0;i<k;i++){
		m+=v[i];	
	}
		cout<<m;
	
	return 0;
}