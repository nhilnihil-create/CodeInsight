#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string A,B;
  cin >> A >> B;
  if(A.size() > B.size()){
    cout << "GREATER";
  }
  else if(A.size() < B.size()){
    cout << "LESS";
  }
  else{
    rep(i,A.size()){
      if(A[i] > B[i]){
        cout << "GREATER";
        return 0;
      }
      else if(A[i] < B[i]){
        cout << "LESS";
        return 0;
      }
    }
    cout << "EQUAL";
  }
}
     