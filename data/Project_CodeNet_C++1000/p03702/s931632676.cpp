#include <bits/stdc++.h>
using namespace std;
#define int long long
	const int vmax=1e5+10;
	int n,a,b;
	int h[vmax];

bool check(int t){
		int num=0;
	for(int i=0;i<n;i++){
		if(h[i]<=t*b)continue;
		num+=(1+(h[i]-t*b-1)/(a-b));


//			if(num>t)return false;
	}
    return num<=t;
}


signed main(){
	cin>>n>>a>>b;

	for(int i=0;i<n;i++)cin>>h[i];
	int l=0ll,r=1e9;
	while(r-l>1){
	int m=(l+r)/2;
	if (check(m)){r=m;}
	else {l=m;}
	}
	cout<<r	<<endl;

}