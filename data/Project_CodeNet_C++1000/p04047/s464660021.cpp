#include <bits/stdc++.h> 
using namespace std;
typedef long long intl;
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	vector <int> v(2*n);
	for(int i=0;i<2*n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=v[i*2];
	}
	cout<<sum<<endl;
	
}