#include <iostream>
#include <algorithm>

using namespace std;

int const NMAX = 100;
int v[1 + NMAX + 1];

int main() {

  string n;
  cin >> n;
  bool N, E, W, S;
  N = E = W = S = false;
  for(int i = 0;i < n.size();i++){
    if(n[i] == 'N'){
      N = true;
    }else if(n[i] == 'E'){
      E = true;
    }else if(n[i] == 'W'){
      W = true;
    }else if(n[i] == 'S'){
      S = true;
    }
  }
  if((N == S) && (E == W)){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
