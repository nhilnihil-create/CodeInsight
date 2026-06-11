#include<iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<numeric>

using namespace std;

long long MOD = 1000000007;

int n,m;
long long in[100005];
long long diff[100005];
long long x,y;

long long ans(int k){
  for(int i=0;i<k-1;i++){
    diff[i] = in[i+1]-in[i];
  }
  long long ret = 0;
  for(int i=0;i<k-1;i++){
    long long tmp = diff[i] * (long long)(i+1);
    tmp %= MOD;
    tmp *= (long long)(k-1-i);
    tmp %= MOD;
    ret += tmp;
    ret %= MOD;
  }
  return ret;
}

int main(){
  cin>>n>>m;

  for(int i=0;i<n;i++){
    cin>>in[i];
  }
  x = ans(n);

  for(int i=0;i<m;i++){
    cin>>in[i];
  }
  y = ans(m);

  cout<<((x*y)%MOD)<<endl;

  return 0;
}