#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  int ans=10;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0){
      int p=n/i;
      int count=0;
      while(p){
        p/=10;
        count++;
      }
      ans=min(ans,count);
    }
  }
  cout << ans << endl;
}