#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979
using ll = long long;
using P = pair<int,int>;

ll divisor=1e9+7;
int main(){
	ll a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	rep(i,3){
		if(a[i]%2==0){
			puts(0);
			return 0;
		}
	}
	puts(a[0]*a[1]);
}
