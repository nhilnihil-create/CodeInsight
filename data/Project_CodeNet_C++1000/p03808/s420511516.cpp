#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
	int n; cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}
	int per = (n*(n+1))/2;
	if(sum%per != 0){
		cout<<"NO"<<endl;
		return 0;
	}
	
	vector<int> b(n);
	for(int i = 0; i < n-1; i++){
		b[i] = a[i+1] - a[i];
	}
	b[n-1] = a[0] - a[n-1];
	int k = sum/per;
	int bsum = 0;
	bool done = false;
	for(int i = 0; i < n; i++){
		if((k - b[i])%n != 0 || (k - b[i]) < 0){
			done = true;
			break;
		}
	}
	if(done){
		cout<<"NO"<<endl;
		return 0;
	}else{
		cout<<"YES"<<endl;
	}
	
	
}
