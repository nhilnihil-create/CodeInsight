#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n,k;cin>>n>>k;
  vector<long long> A(n);for(int i = 0; n > i; i++)cin>>A[i];
  long long ans = 1000000000000000LL;
  for(int bit = 0; (1<<(n-1)) > bit; bit++){
    if(__builtin_popcount(bit)+1 != k)continue;
    long long he = A[0];
    long long tmp = 0;
    for(int i = 0; n > i; i++){
      if(bit & (1<<i)){
        if(he < A[i+1]){
          he = A[i+1];
        }else{
          he++;
          tmp +=he-A[i+1];
        }
      }else{
        he = max(he,A[i+1]);
      }
    }
    ans = min(ans,tmp);
  }
  cout << ans << endl;
}
    
