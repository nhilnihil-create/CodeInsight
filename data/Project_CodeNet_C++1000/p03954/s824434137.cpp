#include<bits/stdc++.h>
using namespace std;
int n,a[400010],lbound,rbound,mid,ans;
bool zz(int x){
  	return !(x<=mid);
}
bool check(){
	for (int i=1;i<=n-1;i++){
		if (zz(a[n+i-1])==zz(a[n+i])) return zz(a[n+i]);
		if (zz(a[n-i+1])==zz(a[n-i])) return zz(a[n-i+1]);
	}
	return zz(a[1]);
}
int main(){
	cin>>n;
	for (int i=1;i<=2*n-1;i++) cin>>a[i];
	lbound=1;rbound=2*n-1;
	while (lbound<=rbound){
		mid=(lbound+rbound)/2;
		if (!check()){
			rbound=mid-1;
			ans=mid;
		}
		else
			lbound=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}