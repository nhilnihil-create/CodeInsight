#include <bits/stdc++.h>
#define r(i,n) for(long long i = 1; i<=n; i++)
typedef long long ll;
using namespace std;

int main() {
  int n,sum=0,ans,ex;
  cin >> n;
  r(i,n){
    sum+=i;
    if(sum>=n){
      ans=i;
      ex=sum-n;
      break;
    }
  }
  r(i,ans){
    if(i!=ex)cout<<i<<endl;
  }
}