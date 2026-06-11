#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i*(m-j)+j*(n-i)==k){
				cout<<"Yes"<<"\n";
				return 0;
			}
		}
	}
	cout<<"No"<<"\n";
}