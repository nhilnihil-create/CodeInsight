#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	int a[n];
	rep(i,n) cin>>a[i];

	int sum=0,cnt=1;
	rep(i,n-1){
		int b=a[i+1]-a[i];
		if(sum<=0&&b<=0) sum+=b;
		else if(sum>=0&&b>=0) sum+=b;
		else {
			//cout<<i<<endl;
			cnt++;
			sum=0;
		}
	}

	cout<<cnt<<"\n";
}