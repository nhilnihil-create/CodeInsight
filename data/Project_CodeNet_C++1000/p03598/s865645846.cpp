#include <bits/stdc++.h>
using namespace std;

int main(){
  int X[110];
  
  int N,K,ans = 0;
  cin >> N >> K;
  
  for (int i = 0;i < N; i++){
    cin >> X[i];
  }
  
  for (int i = 0;i < N; i++){
    int temp = min(X[i],K - X[i]);
    ans += temp;
  }
  cout << 2 * ans << endl;
}