#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  int64_t ans=1e9;
  for(int i=a.front();i<=a.back();i++){
    int64_t sum=0;
    for(int j=0;j<N;j++){
      sum+=pow(a.at(j)-i,2);
    }
    if(ans>sum){
      ans=sum;
    }
  }
  cout << ans << endl;
  return 0;
}
