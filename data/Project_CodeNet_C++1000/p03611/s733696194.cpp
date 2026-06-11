#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[100005];
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		cnt[a]++;cnt[a+1]++;
		if(a>0)cnt[a-1]++;
	}
	int mx=0;
	for(int i=0;i<100005;i++){
		mx=max(mx,cnt[i]);
	}
	cout<<mx;
	return 0;
}