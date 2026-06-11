#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S;
  cin >> S;
  
  int N = S.size();
  sort(S.begin(), S.end());
  
  vector<bool> tof(26,false);
  
  int cnt=0;
  for(int i=0; i<N; i++){
    cnt = (int)(S.at(i) - 'a');
    tof.at(cnt) = true;
  } 
  
  for(int i=0; i<26; i++){
    if(tof.at(i) == false){
      cout << (char)(i + 'a') <<endl;
      return 0;
    }
  }
  
  cout << "None" << endl;
  
}
