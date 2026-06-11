#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, B=0, cnt=1;
  cin >> N;
  vector<int> A(N);
  cin >> A.at(0);
  rep(i, N-1){
    cin >> A.at(i+1);
    if(A.at(i+1)>A.at(i)){
      if(B==-1){
        cnt++;
        B=0;
      }
      else if(B==0) B=1;
    }
    else if(A.at(i+1)<A.at(i)){
      if(B==1){
        cnt++;
        B=0;
      }
      else if(B==0) B=-1;
    }
  }
  cout << cnt << endl;
}