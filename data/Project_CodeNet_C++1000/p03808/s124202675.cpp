#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	ll a[n], sum=0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum+=a[i];
	}
	
	if(sum%(n*(n+1)/2)!=0){
		cout << "NO" << endl;
		return 0;
	}

	ll k=sum/(n*(n+1)/2), d[n];
	for(int i=0; i<n-1; i++) d[i]=a[i]-a[i+1];
	d[n-1]=a[n-1]-a[0];

	ll cnt=0;
	for(int i=0; i<n; i++){
		if((d[i]+k)%n!=0 || d[i]+k<0){
			cout << "NO" << endl;
			return 0;
		}else cnt+=(d[i]+k)/n;
	}
	if(cnt==k) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}