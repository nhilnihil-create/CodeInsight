#include<bits/stdc++.h>
using namespace std;
// nCk
int64_t nCk(int64_t a, int64_t b){
  int64_t c = 1;
  for(int i=1; i<=b; i++){
    c *= a +1 - i;
    c /= i;
  }
  return c;
}


int main(){
  int64_t N, A, B;
  cin >> N >> A >> B;
  vector<int64_t> vec(N);
  for(int i=0; i<N; i++){
    cin >> vec.at(i);
  }
  sort(vec.rbegin(),vec.rend());
  int64_t sum = 0;
  int64_t cnt = 0;
  int64_t begin = 100;
  int64_t end = -1;
  for(int64_t i=0; i<N; i++){
    if(i < A){
      sum += vec.at(i);
    }
    if(vec.at(i) == vec.at(A-1)){
      cnt++;
      begin = min(begin,i);
      end = i+1;
    }
  }
  
  cout << setprecision(20) << (double)sum / (double)A << endl;
  int64_t ans = 0;
  if(vec.at(0) != vec.at(A-1)){
    ans = nCk(cnt,A-begin);
  }
  else{
    for(int i=A; i<=B; i++){
      if(vec.at(i-1) != vec.at(A-1)){
        break;
      }
      ans += nCk(end,i);
    }
  }
  cout << ans << endl;
}  