#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin >> S;
  string T;
  cin >> T;
  int N = S.size();
  int M = T.size();
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    if (S[i] == 'A'){
      A[i] = 1;
    } else {
      A[i] = 2;
    }
  }
  vector<int> sumA(N + 1, 0);
  for (int i = 0; i < N; i++){
    sumA[i + 1] = sumA[i] + A[i];
  }
  vector<int> B(M);
  for (int i = 0; i < M; i++){
    if (T[i] == 'A'){
      B[i] = 1;
    } else {
      B[i] = 2;
    }
  }
  vector<int> sumB(M + 1, 0);
  for (int i = 0; i < M; i++){
    sumB[i + 1] = sumB[i] + B[i];
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    c--;
    if ((sumA[b] - sumA[a]) % 3 == (sumB[d] - sumB[c]) % 3){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}