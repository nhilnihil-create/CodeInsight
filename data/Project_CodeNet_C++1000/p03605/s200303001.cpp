#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;
  string S = to_string(N);
  if (S.at(0) == '9' || S.at(1) == '9'){
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  
}