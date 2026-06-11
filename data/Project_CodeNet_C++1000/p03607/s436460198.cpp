#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long N, i, cnt = 0;
  cin >> N;
  map<long long, int> A;

  for(i=0; i<N; i++){
    long long a;
    cin >> a;
    A[a]++;
  }
  
  for(auto p : A){
    cnt += p.second%2;
  }
  cout << cnt << endl;
  return 0;
}