#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int N,K,X,Y;
  	cin>>N>>K>>X>>Y;
  	int sum=0;
  	if(N<=K) sum+=N*X;
  	else sum+=K*X+(N-K)*Y;
  	cout<<sum<<endl;
}