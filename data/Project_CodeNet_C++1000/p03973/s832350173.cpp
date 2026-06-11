#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int n,i,a[100005],curr_price,ans=0,curr_max=1;
	cin>>n;
	for(i=0;i<n;i++) {
		cin>>a[i];
	}
	
	if(a[0]>=2) {
		ans+=(a[0]-1);
	}
	
	for(i=1;i<n;i++) {
		// cout<<"i is "<<i<<" a[i]: "<<a[i]<<endl;
		curr_price = curr_max+1;
		if(curr_price<a[i]) {
			if(curr_max==1) {
				if(a[i]%2==0) {
					ans+=(a[i]/2-1);
					a[i]=1;
				} else {
					ans+=(a[i]/2);
					a[i]=1;
				}
			} else if(a[i]%curr_price>0) {
				ans+=(a[i]/curr_price);
				a[i]=a[i]%curr_price;
			} else {
				ans+=(a[i]/curr_price-1);
				a[i]=curr_max;
			}
		}
		curr_max=max(curr_max,a[i]);
		// cout<<"ans: "<<ans<<" "<<"curr_max: "<<curr_max<<endl;
	}
	cout<<ans<<endl;
	return 0;
}