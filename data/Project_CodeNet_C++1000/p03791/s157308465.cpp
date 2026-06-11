#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
	using namespace std;
const int N=100010;
const int MO=1e9+7;
int n;
int x[N];
int c[N];
long long ans=1;
long long calc(int p){
	if (p==1) return 1;
	else return p*calc(p-1)%MO;
}
int last=0;
int main(){
	cin>>n;
	x[0]=-1;
	for (int i=1;i<=n;i++)  {
		cin>>x[i];
		x[i]=min(x[i-1]+2,x[i]);
	}
	for (int i=1;i<=n;i++) {
	//	cout<<x[i]<<' ';
		ans=ans*((x[i-1]+1)/2+1)%MO;
	}
//	cout<<2*calc(12)<<endl;
	cout<<ans<<endl;
	return 0;
}