#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define dbg(n) cout<<#n<<' '<<n<<endl;
int power(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	int t;
	cin>>t;
	map<int,int> mp;
	int a[200001];
	for(int i=0;i<t;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	sort(a,a+t);
	int count=0;
	for(int i=0;i<t;i++){
		if(abs(mp[a[i]]-i)%2!=0){count++;}
	}	
	cout<<count/2<<endl;
}

