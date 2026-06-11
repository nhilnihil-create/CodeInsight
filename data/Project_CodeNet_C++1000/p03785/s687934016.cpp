#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	ll N,C,K;
  	cin>>N>>C>>K;
  	ll A[N];
  	rep(i,N) cin>>A[i];
  	sort(A,A+N);
  	ll count=0;
    ll pass=0;
  	ll i=0;
  	while(i<N){
      	pass=0;
        count++;
		rep(j,C){
          	if(i+j>=N) break;
         	if(A[i]+K>=A[i+j]) pass++;
        }
      	i+=pass;
    }
  	
  	cout<<count<<endl;
}