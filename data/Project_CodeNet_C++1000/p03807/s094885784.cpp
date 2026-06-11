#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int odd = 0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    odd += A.at(i) % 2;
  }
  
  if(odd % 2 == 0)  cout << "YES" << endl;
  else  cout << "NO" << endl;
}