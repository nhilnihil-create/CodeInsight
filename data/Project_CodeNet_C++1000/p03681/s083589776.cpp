#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int facctorialMethod(int k){
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum = (sum%(1000000000+7))*(i%(1000000000+7));
    }
    return sum%(1000000000+7);
}
int main()
{
  
  int n,m;
  ll ans=0;
  cin >> n >>m;
  ll N,M;
  N=facctorialMethod(n);
  M=facctorialMethod(m);
  if(max(n,m)-min(n,m)>1)ans=0;
  else if(n==m){
    ans = N * M *2 %(1000000000+7);  
  }
  else{
    ans = N * M %(1000000000+7);
  }
  cout <<ans << endl;
      return 0;
}
