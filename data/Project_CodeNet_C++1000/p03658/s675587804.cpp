#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	ll n,k,sum=0,ar[100];
	cin>>n>>k;
	for(ll i=0;i<n;i++){
		cin>>ar[i];
	}
	ll dif=n-k;
	sort(ar,ar+n);
	for(ll i=dif;i<n;i++) sum+=ar[i];
	cout<<sum<<endl;
	return 0;
}