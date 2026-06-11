#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
	char S[222];
  	cin>>S;
  	int n=strlen(S);
  
  	for(int i=n-2;i;i-=2){
      if(strncmp(S,S+i/2,i/2)==0) {
        cout<<i<<endl;
      	return 0;
      }
    }
  	
  	return 0;
}