#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> a;
  for (int i = 0; i < N; i++) {
    int v; cin >> v; a.push_back(v);
  }
  sort(a.begin(), a.end());
  bool ok = true;
  if (a[0] < a[1]) {
    int m = a[0];
    int p = 0;
    if (a[1] != m+1) {ok = false;}
    
    for (int i = 1; i < N-1; i++) {
      if (a[i] < a[i+1]) {
        if (i-p < 2 || a[i]+1 != a[i+1]) {ok = false;}
        p = i;
      }
    }
    if (a[N-1] != 2*m || a[N-2] != 2*m) {ok = false;}
  }
  
  if (a[0] == a[1] && N > 2) {
    int m = a[0];
    int p = 1;
    if (a[2] != m+1) {ok = false;}
    for (int i = 2; i < N-1; i++) {
      if (a[i] < a[i+1]) {
        if (i-p < 2 || a[i]+1 != a[i+1]) {ok = false;}
        p = i;
      }
    }
    if (a[N-1] != 2*m-1 || a[N-2] != 2*m-1) {ok = false;}
  }
  
  if (a[0] == a[1] && N == 2) {
    if (a[0] != 1) {ok = false;}
  }
  
  if (ok) {cout << "Possible" << endl;}
  else {cout << "Impossible" << endl;}
}