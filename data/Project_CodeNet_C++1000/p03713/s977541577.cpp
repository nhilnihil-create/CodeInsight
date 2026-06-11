#include<bits/stdc++.h>
using namespace std;

int main() {
	long long h,w,ans=LLONG_MAX,a,b,c;
	cin>>h>>w;
	for (int i=0; i<2; i++) {
		if(i) swap(h,w);
		for (int i=1; i<h; i++)
			a=i*w,
			b=max((h-i)*(w/2),((h-i)/2)*w),
			c=h*w-a-b,
			ans=min(ans,max({a,b,c})-min({a,b,c}));
	}
	cout<<ans<<"\n";
	return 0;
}