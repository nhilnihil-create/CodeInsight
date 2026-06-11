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
	int a,b;
  	cin>>a>>b;
  	if(a%3==0||b%3==0||(a+b)%3==0) cout<<"Possible"<<endl;
  	else cout<<"Impossible"<<endl;
}