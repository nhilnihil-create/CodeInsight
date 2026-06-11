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
  	int A,B,C,D;
  	cin>>A>>B>>C>>D;
  	int count=0;
  	int sw[101];
  	rep(i,101){
		sw[i]=0;
    }
  
  	for(int i=A;i<=B;i++){
     	sw[i]++;	 
    }
  	for(int j=C;j<=D;j++){
      	sw[j]++;
    }
  
  	rep(i,100){
     	if(sw[i]==2 && sw[i+1]==2) count++; 
    }
  	cout<<count<<endl;
}