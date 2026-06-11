#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
  ll N,A,B;
  cin >> N >> A >> B;
  if(A > B){
    cout << 0 << endl;
    return(0);
  }
  if(N == 1 && A != B){
    cout << 0 << endl;
    return(0);
  }
  if(N == 1 && A == B){
    cout << 1 << endl;
    return(0);
  }
  if(N == 2){
    cout << 1 << endl;
    return(0);
  }
  
  cout << (N-2)*(B-A)+1 << endl;
  return(0);
}