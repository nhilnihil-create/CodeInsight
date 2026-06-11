#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int ans = INT_MAX;
	for(int x=a[0];x<=a[n-1];x++){
		//transform everyone to x 
		int c = 0;
		for(int i=0;i<n;i++){
			c+=(pow(a[i]-x,2));
		}
		ans=min(ans,c);
	}
	cout<<ans<<endl;
}