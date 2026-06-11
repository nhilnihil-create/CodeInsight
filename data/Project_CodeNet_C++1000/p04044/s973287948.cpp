#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,l;
	cin>>n>>l;
	vector<string> v(n);
	for(int i=0;i<n;i++)cin>>v[i];
	sort(v.begin(),v.end());
	for(auto it=v.begin();it != v.end();it++)cout<<*it;
	return 0;
	}
