#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[50];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<50;i++){
		a[i]=i;
		//cout << a[i]<<endl;
	}
	ll sum=n/50;
	for(ll i=0;i<50;i++){
		a[i]+=sum;
	}
	sum=n%50;
	for(ll i=0;i<sum;i++){
		for(ll j=0;j<50;j++){
			if(j==i){
				a[j]+=50;
			}
			else{
				a[j]--;
			}
		//	cout << a[j]<<endl;
		}
	}
	cout << 50<<endl;
	for(ll i=0;i<50;i++){
		cout << a[i]<< " ";
	}
	// your code goes here
	return 0;
}