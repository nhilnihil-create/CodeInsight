// In the  name of god
#include <bits/stdc++.h>
#pragma GCC optimze("02")
using namespace std;
using ll=long long;
const ll maxn=2e5+5;
ll n,x,a[maxn];
int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin>>n>>x;
	if(x==1||x==2*n-1)cout<<"No";
	else{
		cout<<"Yes"<<endl;
		for(int i=1;i<2*n;i++)a[i]=i;
		swap(a[n],a[x]);swap(a[x-1],a[n-1]);swap(a[x+1],a[n+1]);
		if(x==n-1)swap(a[n],a[n+1]);
		if(x==n+1)swap(a[n],a[n-1]);
		for(int i=1;i<2*n;i++)cout<<a[i]<<endl;
	}
}
