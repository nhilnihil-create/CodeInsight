#include<bits/stdc++.h>
using namespace std;

vector<int> mkper(vector<int> p, int n){
  vector<int> perm(n);
  for (int i=0;i<n;i++){
    perm[i] = i;
  }
  vector<int> nex(n);
  int peak = n;
  for (int i=0;i<n;i++){
    nex[i] = perm[p[i]];
    for (int j=p[i];j<peak-1;j++){
      perm[j] = perm[j+1];
    }
    peak -= 1;
  }
  return nex;
}
int main(){
  int N, M, R;
  cin >> N >> M >> R;
  vector<int> r(R);
  for (int i=0;i<R;i++){
    cin >> r[i];
    r[i] -= 1;
  }
  vector<vector<long long>> d(N, vector<long long>(N, 100000000000));
  int A, B, C;
  for (int i=0;i<M;i++){
    cin >> A >> B >> C;
    d[A-1][B-1] = C;
    d[B-1][A-1] = C;
  }
  for (int k=0;k<N;k++){
    for (int i=0;i<N;i++){
      for (int j=0;j<N;j++){
        if (d[i][j] > d[i][k] + d[k][j]){
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }
  vector<int> L(R);
  vector<int> LL(R);
  long long m = 100000000000000, tmp = 0, fact = 1, tmp2;
  for (int i=0;i<R;i++){
    fact *= i + 1;
  }
  for (int i=0;i<fact;i++){
    tmp2 = i;
    for (int j=0;j<R;j++){
      LL[R-j-1] = tmp2 % (j+1);
      tmp2 /= j + 1;
    }
    L = mkper(LL, R);
    tmp = 0;
    for (int j=0;j<R-1;j++){
      tmp += d[r[L[j]]][r[L[j+1]]];
    }
    if (m > tmp){
      m = tmp;
    }
  }
  cout << m << endl;
  return 0;
}