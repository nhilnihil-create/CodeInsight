#include<bits/stdc++.h>
using namespace std;

//#define mod      1e9+7
#define INF      1e9+9;
#define ps(x,y)  fixed<<setprecision(y)<<x
# define PI 3.14159265358979323846264338327950 L
typedef long long ll;
typedef unsigned long long ull;
long long mod=1e9+7;
ll binpow(int a,int b){
	ll ans=1;
	while(b--){
		ans*=a;
		ans%=mod;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,num;
	cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>num;
		mp[num]++;
	}
	if(n&1 && mp[0]!=1){
		cout<<"0\n";
		return 0;
	}
	if(n%2==0 && mp[0]!=0){
		cout<<"0\n";
		return 0;
	}
	if(n&1){
		for(int i=2;i<n;i+=2){
			if(mp[i]!=2){
				cout<<"0\n";
				return 0;
			}
		}
	}
	if(n%2==0){
		for(int i=1;i<n;i+=2){
			if(mp[i]!=2){
				cout<<"0\n";
				return 0;
			}
		}
	}
	ll ans=binpow(2,n/2);
	cout<<ans<<endl;
	return 0;
}
