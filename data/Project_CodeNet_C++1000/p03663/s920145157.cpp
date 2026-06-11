#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const ll N=1e9,INF=~0u>>2;
ll n,ans,i,len,l,r,mid;
string rep;
int main(){
//	freopen("ex.in","r",stdin);
	cout<<"? 10000000000"<<endl;
	cin>>rep;
	if(rep=="Y"){
		ans=2;
		while(1){
			cout<<"? "<<ans<<endl;
			cin>>rep;
			if(rep=="Y"){
				cout<<"! "<<ans/2<<endl;
				return 0;
			}
			ans*=10;
		}
	}
	r=10;
	while(1){
		cout<<"? "<<r<<endl;
		cin>>rep;
		if(rep=="N") break;
		r*=10;
	}
	l=r/10;
	r--;
	while(r>l){
		mid=(l+r)>>1;
		cout<<"? "<<mid<<"0"<<endl;
		cin>>rep;
		if(rep=="Y") r=mid;
		else l=mid+1;
	}
	cout<<"! "<<r<<endl;
	return 0;
}