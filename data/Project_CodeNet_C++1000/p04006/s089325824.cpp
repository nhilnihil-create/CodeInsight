#include<iostream>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
ll a[2050];ll n;ll x;
ll cyz[2050];
int main(){
	std::ios::sync_with_stdio(false);
	cin>>n;cin>>x;
	for(int i=0;i<n;i++){
		cin>>a[i];cyz[i]=a[i];
	}
	ll minn=inf;ll res=0;
	for(int k=0;k<n;k++){
		ll temp=0;
		for(int i=0;i<n;i++){
			int pos=i-k;
			if(pos<0)pos=n+pos;
			cyz[i]=min(cyz[i],a[pos]);
			temp+=cyz[i];
		}
		temp+=x*k;
		minn=min(temp,minn);
	}
	cout<<minn<<endl;
}