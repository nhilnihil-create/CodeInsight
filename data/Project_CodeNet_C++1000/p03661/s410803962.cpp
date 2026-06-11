#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,ll> P;
typedef pair<P,P> P2;
const ll inf=100000000000000001;
int main() {
	int n;
	cin>>n;
	ll t=0;
	ll a[200001]={};
	ll a1;
	for(int i=0;i<n;++i){
		cin>>a1;
		t+=a1;
		a[i]=t;
	}
	ll r=inf;
	for(int i=0;i<n-1;++i){
		r=min(r,abs(t-a[i]*2));
	}
	cout<<r<<endl;
	return 0;
}
