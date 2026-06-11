#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> v(N*3);
  for(int i=0;i<N*3;i++){
    cin >> v.at(i);
  }
  sort(v.begin(),v.end(),greater<int>());
  int64_t ans=0;
  for(int i=1;;i+=2){
    ans+=v.at(i);
    if((i+1)/2==N){
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
