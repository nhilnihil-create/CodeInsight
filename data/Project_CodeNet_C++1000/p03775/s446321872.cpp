#include<bits/stdc++.h>
using namespace std;
int get(int64_t k){
    int cnt=0;
    for(int64_t i=1;i<100000000000;i*=10){
      if(k>=i)cnt++;
      else break;
    }
  return cnt;
}
int main(){
  int64_t n;
  cin >> n;
  int64_t ans=get(n);
  for(int64_t i=1;i<=sqrt(n);i++){
    if(n%i==0){
      int64_t j=n/i;
      int k=max(get(i),get(j));
      if(k<ans)ans=k;
    }
  }
  cout << ans << endl;
}
     
