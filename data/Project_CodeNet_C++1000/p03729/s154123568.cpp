#include <bits/stdc++.h>
using namespace std;

int main(){
  const int N= 3;
  vector<string> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }
  
  bool is_satisfied= true;
  for(int i=1; i<N; i++){
    if(data.at(i-1).back()!=data.at(i).at(0)){
      is_satisfied= false;
      break;
    }
  }

  string ans= (is_satisfied) ? "YES"
                             : "NO";
  
  cout << ans << endl;
}