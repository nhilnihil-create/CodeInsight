#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;string s,t;
	cin>>n>>s>>t;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s.substr(n-i,i)==t.substr(0,i))  cnt=max(cnt,i); 
	}
	cout<<2*n-cnt<<"\n";
}