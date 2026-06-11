#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int a[M], b[M];
  int c[N];
    
  for(int i=0; i<N; i++)
    c[i] = 0;
  
  for(int i=0; i<M; i++){
    cin >> a[i] >> b[i];
    c[a[i]-1] += 1;
    c[b[i]-1] += 1;
  }

  for(int i=0; i<N; i++){
    cout << c[i] << endl;
  }
  
  return 0;
}
