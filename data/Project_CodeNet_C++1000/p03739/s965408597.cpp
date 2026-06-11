#include <bits/stdc++.h>
using namespace std;
main(){
  int64_t i;
  int64_t n;cin >> n;
  vector<int64_t> a(n);for(int i=0;i<n;i++) cin >> a[i];
  int64_t sum=0,ans0=0,ans1=0;
  
  for(i=0;i<n;i++){
    sum += a[i];
    if(i%2==0 && sum<=0){
      ans0 += abs(sum) +1;
      sum = 1;
    } else if(i%2==1 && sum>=0){
      ans0 += abs(sum) +1;
      sum = -1;
    }
  }
  
  sum=0;

  for(i=0;i<n;i++){
    sum += a[i];
    if(i%2==0 && sum>=0){
      ans1 += abs(sum) +1;
      sum = -1;
    } else if(i%2==1 && sum<=0){
      ans1 += abs(sum) +1;
      sum = 1;
    }
  }
  
  cout << min(ans0,ans1) << endl;
  return 0;
}