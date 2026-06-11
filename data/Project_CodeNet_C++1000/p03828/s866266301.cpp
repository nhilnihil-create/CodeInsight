#include<iostream>
using namespace std;
int main(){
  int n,i,k,x;cin >> n;
  int prime[997] = {};
  for(i=1;i<=n;i++){
    x = i;
    for(k=2;k<=x;k++){
      while(x%k==0){
        prime[k-1]++;x /= k;
      }
    }
  }
  long long ans = 1;
  for(i=0;i<997;i++) ans = (ans*(prime[i]+1))%1000000007;
  cout << ans << endl;
}
      