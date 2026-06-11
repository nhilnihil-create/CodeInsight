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
	int N,M;
  	cin>>N>>M;
  	int count[N]={0}; //都市から伸びている道路の数
  	
  	rep(i,M){
     	 int a,b;
      	 cin>>a>>b;
      	 a--; b--;
      	 count[a]++;
      	 count[b]++;
    }
  
  	rep(i,N) cout<<count[i]<<endl;
  
}