#include <bits/stdc++.h>
using namespace std;

long long x, n, cnt[100010], ans, m;

int main () {
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>x;
		cnt[x-1]++;
		cnt[x]++;
		cnt[x+1]++;
		m=max(m, x);
	}
	
	for(int i=-1; i<=m+1; i++){
		if(cnt[i]>ans) ans=cnt[i];
	}
	cout<<ans<<endl;
}