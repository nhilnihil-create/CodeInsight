#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(ll i=0;i<n;i++)



int main() {
	ll K,S;
  	cin>>K>>S;
  	ll count=0;
  
  	rep(x,K+1){
     	rep(y,K+1){
         	 if(0<=S-x-y&& S-x-y<=K){
              	count++; 
             }
        }
    }
  	cout<<count<<endl;
}