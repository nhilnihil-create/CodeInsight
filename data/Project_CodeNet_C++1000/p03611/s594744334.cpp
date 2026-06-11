#include <iostream>
#include <vector>
using namespace std;

const long long MAX= 1e5 + 5;

int main(void){
  int N;
  cin >> N;
  vector<long long> a(N);
  vector<long long> bucket(MAX);

  for(long long i=0; i<N; i++){
     cin >> a[i];
     bucket[a[i]]++;
  }//for
   
  long long ans = bucket[0] + bucket[1];
  for(long long i=1; i<=MAX; i++){
     long long count = bucket[i-1] + bucket[i] + bucket[i+1];
     ans = max(ans, count);
  }//for

  cout << ans << "\n";
}//main
