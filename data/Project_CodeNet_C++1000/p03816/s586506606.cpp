#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  /*
  for(int i = 0; i < N; i++) cout << A[i] << " ";
  cout <<endl;
  //*/
  vector<int> maisu(100001);
  for(int i = 0; i < N; i++){
    maisu[A[i]]++;
  }
  int daburi = 0;
  for(int i = 0; i < 100001; i++){
    if(maisu[i] > 0){
      maisu[i]--;
    }
      daburi += maisu[i];
  }
  if((N - daburi) % 2 != 1){
    daburi++;
  }
  cout << N - daburi <<endl;
}