#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(vector<ll> &a, int idx) {
	ll sum=0, n=a.size();
	for (int i=0; i<=idx; i++)
		sum+=a[i];
	for (int i=idx+1; i<n; i++) {
		if(sum*2<a[i])
			return false;
		sum+=a[i];
	}
	return true;
}
 
int main() {
	int n; cin>>n;
	vector<ll> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	int l=0, r=n-1;
	while(l<r){
		int mid=(l+r)/2;
		if(check(a,mid)) r=mid;
		else l=mid+1;
	}
	cout<<n-l<<"\n";
	return 0;
}