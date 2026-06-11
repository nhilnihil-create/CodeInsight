#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[114514];
int main(){
	ll n,l;
	cin>>n>>l;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll num=-1;
	for(int i=1;i<n;i++){
		if(a[i]+a[i+1]>=l){
			num=i;
			break;
		}
	}
	if(num==-1)cout<<"Impossible\n";
	else{
		cout<<"Possible\n";
		for(int i=1;i<num;i++)cout<<i<<endl;
		for(int i=n-1;i>num;i--)cout<<i<<endl;
		cout<<num<<endl;
	}
	return 0;
}