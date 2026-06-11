#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  int prev_max = 0;
  long long ans = 0;
  for(auto a: A){
    if(a <= prev_max){
      continue;
    }else if(a == prev_max + 1){
      prev_max = a;
    }else{
      ans += (a - 1) / (prev_max + 1);
      prev_max = max(prev_max, 1);
    }
    //cout << ans << endl;
  }
  cout << ans << endl;
}
