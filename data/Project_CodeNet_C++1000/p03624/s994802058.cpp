#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S;
  cin >> S;
  
  int N = S.size();
  sort(S.begin(), S.end());
  
  for(char i='a'; i<='z'; i++){
    int ans =0;
    for(int j=0; j<N; j++){
      if(S.at(j) == i){
        ans++;
      }
    }
  
    if(ans == 0){
      cout << i << endl;
      return 0;
    }
    
  }
  
  cout << "None" << endl;
 
}
