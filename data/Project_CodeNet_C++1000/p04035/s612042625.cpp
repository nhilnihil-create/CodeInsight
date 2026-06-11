#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, L;
  cin >> N >> L;
  vector<int> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  int pos = -1;
  for (int i = 0; i < N - 1; i++){
    if (a[i] + a[i + 1] >= L){
      pos = i + 1;
    }
  }
  if (pos == -1){
    cout << "Impossible" << endl;
  } else {
    cout << "Possible" << endl;
    for (int i = 1; i < pos; i++){
      cout << i << endl;
    }
    for (int i = N - 1; i > pos; i--){
      cout << i << endl;
    }
    cout << pos << endl;
  }
}