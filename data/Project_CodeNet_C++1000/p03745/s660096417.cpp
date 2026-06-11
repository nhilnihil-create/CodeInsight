#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  if(N==1){
    cout << 1 << "\n";
    return 0;
  }
  
  int cnt = 1;
  vector<bool> ud;
  for(int i=1;i<N;i++){
    if(A.at(i-1)==A.at(i)){
      continue;
    }else{
      ud.push_back( A.at(i-1) < A.at(i) );
    }
  }
  for(int i=0;i<ud.size()-1;i++){
    if(ud.at(i)!=ud.at(i+1)){
      cnt++;
      i++;
    }
  }
  cout << cnt << "\n";
}