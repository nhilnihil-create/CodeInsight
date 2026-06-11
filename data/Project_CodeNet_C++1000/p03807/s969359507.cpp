#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,kisuu=0;
  cin >> N;
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    if(a%2 == 1){
      kisuu++;
    }
  }
  if(kisuu%2 == 1){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}
