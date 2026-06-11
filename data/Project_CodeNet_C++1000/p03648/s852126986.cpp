#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,ll> P;
typedef pair<P,P> P2;
const ll INF=100000000000000001;
int main() {
	ll k;
	cin>>k;

	ll a[50]={};
	for(int i=0;i<50;++i)a[i]=49-i+k/50;
	for(int i=0;i<k%50;++i)a[i]++;
	cout<<"50"<<endl;
	cout<<a[0];
	for(int i=1;i<50;++i)cout<<" "<<a[i];
	cout<<endl;

	return 0;
}
