#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> S(N);
  for(int i=0; i<N; i++){
    cin >> S.at(i);
  }
  
  int ans = 0;
  int sum = 0;
  
  for(int i=0; i<N; i++){
    sum += S.at(i);
  }

  if(sum % 10 != 0){
    ans = sum;    
  }
  else{
    int odd = sum;
    for(int i=0; i<N; i++){
      if(S.at(i) % 10 != 0 && S.at(i) < odd){
        odd = S.at(i);
      }
    }
    if(odd != sum){
      ans = sum - odd;
    }
  }

  cout << ans << endl;
}