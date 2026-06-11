#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, A, B, Sum=0, Sum2=0;
  string S;
  cin >> N >> A >> B >> S;
  rep(i, S.size()){
    if(S.at(i)=='a'){
      if(Sum+1<=A+B){
        cout << "Yes" << endl;
        Sum++;
      }
      else cout << "No" << endl;
    }
    if(S.at(i)=='b'){
      if(Sum+1<=A+B && Sum2+1<=B){
        cout << "Yes" << endl;
        Sum2++;
        Sum++;
      }
      else cout << "No" << endl;
    }
    if(S.at(i)=='c') cout << "No" << endl;
  }
}