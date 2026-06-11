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
	int N;
  	cin>>N;
  	int a[N];
  	int num[100010];
  	rep(i,100009) num[i]=0;
  	
  	rep(i,N) {
      cin>>a[i];
      num[a[i]]++;
    }
  	
  	int m=0;
  
  	rep(i,100000){
      int sum=num[i]+num[i+1]+num[i+2];
      m=max(m,sum);
    }
  
  	cout<<m<<endl;
  
  	
  	
}