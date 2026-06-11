#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, P;
  cin >> N >> P;
  
  vector<int> A(N);
  int kisu = 0, gusu = 0;
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
    if (A.at(i) % 2 == 0){
      gusu++;
    }
    else{
      kisu++;
    }
  }
  
  vector<vector<int>> pascal(N + 1, vector<int>(N + 1));
  pascal.at(0).at(0) = 1;
  for (int i = 1; i < N + 1; i++){
    pascal.at(i).at(0) = 1;
    pascal.at(i).at(i) = 1;
    for (int j = 1; j < i; j++){
      pascal.at(i).at(j) = pascal.at(i - 1).at(j - 1) + pascal.at(i - 1).at(j);
    }
  }
  
  long long int ans, ans_kisu = 0, ans_gusu;
  
  ans_gusu = pow(2, gusu);
  
  int num = P;
  while (num <= kisu){
    ans_kisu += pascal.at(kisu).at(num);
    num += 2;
  }
  
  ans = ans_kisu * ans_gusu;
  cout << ans << endl;

}