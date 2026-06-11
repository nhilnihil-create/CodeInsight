#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> a(N);
  for(int i=0;i<N;i++){
    cin >> a.at(i);
  }
  
  vector<long long> ans(N);
  if(N%2==0){
    for(int i=0;i<N/2;i++){
      ans.at(i) = a.at(N-2*i-1);
    }
    for(int i=0;i<N/2;i++){
      ans.at(i+N/2) = a.at(2*i);
    }
  }else{
    for(int i=0;i<N/2+1;i++){
      ans.at(i) = a.at(N-2*i-1);
    }
    for(int i=0;i<N/2;i++){
      ans.at(i+N/2+1) = a.at(2*i+1);
    }
  }
  
  for(int i=0;i<N;i++){
    cout << ans.at(i) << " " ;
  }
  cout << endl;
}