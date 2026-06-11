#include<bits/stdc++.h>
using namespace std;

long long n,ans;

struct N {
	long long size,color,sum;
}a[100009];

bool cmp(N a,N b) {
	return a.size<b.size;
}

int main() {
	cin>>n;
	for (int i=1; i<=n; ++i) {
		cin>>a[i].size;
		a[i].color=i;
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1; i<=n; ++i) {
		a[i].sum=a[i-1].sum+a[i].size;
	}
	for (int i=n; i>=1; --i) {
		if (a[i].size<=a[i-1].sum*2)
			++ans;
		else break;
	}
	cout<<ans+1<<endl;
}