#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int a,b,x[N];
  int i;
  for(i=0;i<N;i++) x[i] = 0;
  for(i=0;i<M;i++){
    cin >> a >> b;
    x[a-1] += 1;
    x[b-1] += 1;
  }
  for(i=0;i<N;i++) cout << x[i] << endl;
}
  