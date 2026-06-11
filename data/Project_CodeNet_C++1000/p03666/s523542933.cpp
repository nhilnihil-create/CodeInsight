#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
int main(){
	ll n,a,b,c,d;
	cin>>n>>a>>b>>c>>d;
	ll las = b-a;
	for(int i=0;i<=n-1;i++){
		ll ma = d*i - c*(n-1-i);
		ll mi = c*i - d*(n-1-i);
		if(mi <= las && las<=ma){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}