#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0; i<N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<long long> Side(2);
  int cnt=0;
  int temp=0;
  for(int i=0; i<N-1; i++){
    if(cnt==1){
      cnt=0;
      continue;
    }
    if(temp==2) break;
      if(cnt==0 && A.at(i)==A.at(i+1)){
      Side.at(temp)=A.at(i);
      temp++;
      cnt++;
    }
  }
  long long ans = Side.at(0)*Side.at(1);
  cout << ans << endl;
}