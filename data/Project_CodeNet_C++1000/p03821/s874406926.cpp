#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int64_t> A(N),B(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i) >> B.at(i);
  }
  int64_t ans=0;
  for(int i=N-1;i>=0;i--){
    A.at(i)+=ans;
    ans+=B.at(i)*((A.at(i)+B.at(i)-1)/B.at(i))-A.at(i);
  }
  cout << ans << endl;
  return 0;
}
