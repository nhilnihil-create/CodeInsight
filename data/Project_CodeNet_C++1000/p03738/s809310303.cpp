#include <iostream>
#include <string>

using namespace std;

int const NMAX = 1e5;
int v[1 + NMAX];

int main() {

  int n, pos = 1, p, ans = 0;
  //cin >> n;
  string A, B;
  cin >> A >> B;
  if(A.size() < B.size()){
    cout << "LESS";
  }else if(A.size() > B.size()){
    cout << "GREATER";
  }else{
    if(A < B){
      cout << "LESS";
    }else if(A > B){
      cout << "GREATER";
    }else{
      cout << "EQUAL";
    }
  }
  return 0;
}
