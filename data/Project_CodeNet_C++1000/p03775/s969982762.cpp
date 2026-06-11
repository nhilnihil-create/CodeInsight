#include<bits/stdc++.h>
using namespace std;
long long keta(long long x){
  int y=0;
  while(x!=0){
    y++;
    x/=10;
  }
  return y;
}

int main(){
  long long n;
  cin >> n;
  long long ans=11;
  for(int i=1; i<=sqrt(n);i++){
    if(n%i==0){
      ans=min(ans,keta(n/i));
    }
  }
  cout << ans << endl;
}