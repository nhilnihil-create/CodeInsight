#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(void) {
  using namespace std;

  uint N, K;
  cin >> N >> K;
  vector<string> D(K);
  for(uint i=0; i<D.size(); i++)
    cin >> D[i];

  for(uint i=N; i<=10*N; i++) {
    string I = to_string(i);
    bool satisfy = true;
    for(uint j=0; j<D.size(); j++) {
      if(I.find(D[j]) != string::npos){
        satisfy = false;
        break;
      }
    }
    if(satisfy) {
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}
