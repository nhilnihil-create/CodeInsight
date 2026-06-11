#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[52];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<50;i++){
		a[i]=i;
	}
	ll s=n/50;
	for(ll i=0;i<50;i++){
		a[i]+=s;
	}
	s=n%50;
	for(ll i=0;i<s;i++){
		a[49-i]++;
	}
	cout << 50<<endl;
	for(ll i=0;i<50;i++){
		cout <<a[i]<< " ";
	}
	// your code goes here
	return 0;
}