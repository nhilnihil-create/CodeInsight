#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  vector<int> B(N);
  for(int i=0; i<N; i++){
    cin >> B.at(i);
  }
  vector<int> vec(N);
  vector<bool> end(N,false); 
  vec.at(0) = A.at(0);
  end.at(0) = true;
  vec.at(N-1) = B.at(N-1);
  end.at(N-1) = true;
  for(int i=1; i<N; i++){
    if(end.at(i)){
      if(A.at(i) < B.at(i)){
        vec.at(i) = 0;
      }
    }   
    else if(A.at(i) != A.at(i-1)){
      vec.at(i) = A.at(i);
      end.at(i) = true;
    }
    else{
      vec.at(i) = A.at(i);
    }
  }
  for(int i=N-2; i>=0; i--){
    if(B.at(i) != B.at(i+1)){
      if(end.at(i) && A.at(i) != B.at(i)){
        vec.at(i) = 0;
      }
      else{
        vec.at(i) = B.at(i);
        end.at(i) = true;
      }
    }
    else{
      if(end.at(i) && vec.at(i) > B.at(i)){
        vec.at(i) = 0;
      }
      else if(end.at(i)){
        continue;
      }
      else{
        vec.at(i) = min(vec.at(i), B.at(i));
      }
    }
  }
  
  int64_t ans = 1;
  int64_t MOD = 1000000007;
  
  for(int i=0; i<N; i++){
    if(end.at(i) && vec.at(i) > 0){
      continue;
    }
    else{
      ans *= vec.at(i);
      ans %= MOD;
    }
  }
  if(N == 1 && (A.at(0) != B.at(0))){
    ans = 0;
  }
  cout << ans << endl;
}