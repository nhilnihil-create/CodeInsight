#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> vec(N);
  int64_t sum = 0;
  for(int i=0; i<N; i++){
    cin >> vec[i];
    sum += vec[i];
  }
  vector<int64_t> d(N);
  for(int i=0; i<N-1; i++){
    d[i] = vec[i+1] - vec[i];
  }
  d[N-1] = vec[0] - vec[N-1];
  
  bool flag = true;
  int64_t cnt = sum / (N*(N+1)/2);
  if(sum % (N*(N+1)/2) != 0){
    flag = false;
  }
  
  int64_t num = 0;
  for(int i=0; i<N; i++){
    int64_t C = 0;
    while(cnt - C != d[i]){
      if(d[i] > cnt){
        flag = false;
        break;
      }
      d[i] += N-1;
      C++;
      num++;
    }
  }
  
  
  if(flag && num == cnt){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
      
  
}