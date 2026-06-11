#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int main(){
  long long w,h;
  cin >> w >> h;
  vector<long long> p(w),q(h);
  for(int i=0;i<w;i++){
    cin >> p[i];
  }
  for(int i=0;i<h;i++){
    cin >> q[i];
  }
  sort(p.begin(),p.end());
  sort(q.begin(),q.end());
  int pNow=0,qNow=0;
  long long ans=0;
  while(1){
    if(pNow>=w){
      for(;qNow<h;qNow++){
        ans+=q[qNow];
      }
      break;
    }
    if(qNow>=h){
      for(;pNow<w;pNow++){
        ans+=p[pNow];
      }
      break;
    }
    if(p[pNow]<q[qNow]){
      ans+=(h+1-qNow)*p[pNow];
      pNow++;
    }else{
      ans+=(w+1-pNow)*q[qNow];
      qNow++;
    }
  }
  cout << ans << endl;
  return 0;
}
