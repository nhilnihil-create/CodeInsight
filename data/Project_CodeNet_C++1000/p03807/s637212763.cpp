#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,ans = 0;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    if (A.at(i) % 2 != 0) ans++;
  }
  cout << (ans % 2 == 0 ? "YES" : "NO") << endl;
}