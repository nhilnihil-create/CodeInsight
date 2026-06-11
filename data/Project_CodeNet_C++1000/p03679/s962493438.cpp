#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll x,a,b;
  	cin>>x>>a>>b;
  	
  	if(a+x<b) cout<<"dangerous"<<endl;
  	else if(a<b && b<=a+x) cout<<"safe"<<endl;
  	else cout<<"delicious"<<endl;
}