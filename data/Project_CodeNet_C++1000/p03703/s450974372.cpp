#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200100;
ll a[N],b[N];
int n,K;

ll solve(int l,int r){
	if(l==r)return 0;
	int mid=(l+r)/2;
	ll ret=solve(l,mid)+solve(mid+1,r);
	for(int i=l,j=mid+1,cnt=l;i<=mid||j<=r;)
		if(j>r||(i<=mid&&a[i]<=a[j])){ret+=r-j+1;b[cnt++]=a[i++];}
		else b[cnt++]=a[j++];
	for(int i=l;i<=r;++i)a[i]=b[i];
	return ret;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;++i){int x;cin>>x;a[i]=a[i-1]+x-K;}
	cout<<solve(0,n)<<'\n';
	return 0;
}
