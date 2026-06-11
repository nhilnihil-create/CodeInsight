#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
using ll = long long;
using P = pair<int,int>;

int main(){
	ll q,h,s,d,n;
	cin>>q>>h>>s>>d>>n;
	ll cost=min(min(4*q,2*h),s);
	ll cost2 = min(2*cost,d);
	if(n%2==1){
		puts(n/2*cost2+cost);
		return 0;
	}
	puts(n/2*cost2);
}