#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 666666
int arr[N];
vector<int> v1,v0;
int a[N],b[N];
map<int,int> mp;
signed main(){
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++) mp[b[i]]=i;
	for(int i=1;i<=n;i++){
		if(i%2!=mp[a[i]]%2) ans++;
	}
	cout<<ans/2;
	return 0;
}
/*
3
1
2
1
*/