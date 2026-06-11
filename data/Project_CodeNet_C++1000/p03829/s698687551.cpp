#include <bits/stdc++.h>
using namespace std;
     
int main() {
  long long N, A, B;
  cin >> N >> A >> B;
  vector<int> town(N);
  for(int i = 0; i < N; i++){
    cin >> town.at(i);
  }
  
  long long answer = 0;
  
  for(int i = 0; i < N - 1; i++){
    if((town.at(i + 1) - town.at(i)) * A >= B){
      answer += B;
    }
    else{
      answer += (town.at(i + 1) - town.at(i)) * A;
    }
  }
    
    cout << answer << endl;
}