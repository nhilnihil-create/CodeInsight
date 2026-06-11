#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> combination_table(int N) {
  vector<vector<long long>> C(N+1,vector<long long>(N+1));
  for (int i = 0; i <= N; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1]+C[i-1][j];
    }
  }
  return C;
}
int main() {
  int N,A,B,X=0,Y=0;
  cin >> N >> A >> B;
  if (A > B)  {
    cout << "0\n0";
    return 0;
  }
  long long v[N],answer=0;
  double average=0;
  for (int i = 0; i < N; i++) {
    cin >> v[i];
  }
  sort(v,v+N,greater<long long>());
  for (int i = 0; i < A; i++) {
    average += v[i];
    Y += v[A-1] == v[i];
  }
  for (int i = 0; i < N; i++) {
    X += v[A-1] == v[i];
  }
  average /= A;
  cout.precision(20);
  cout << fixed << average << endl;
  vector<vector<long long>> C = combination_table(N);
  if (v[0] == v[A-1]) {
    for (Y = A; Y <= B; Y++) {
      answer += C[X][Y];
    }
  } else {
    answer += C[X][Y];
  }
  cout << answer;
}