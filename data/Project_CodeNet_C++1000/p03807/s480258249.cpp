#include "bits/stdc++.h"
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int odd = 0;
  for(int i=0;i<N;i++){
    cin >> a[i];
    odd += a[i] & 1;
  }
  if(odd%2){
    cout << "NO" ;
  }else{
    cout << "YES";
  }
  cout << endl;
  return 0;
}