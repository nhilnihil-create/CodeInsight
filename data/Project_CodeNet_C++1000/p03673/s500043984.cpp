#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, oma=0;
  cin >> N;
  if (N%2==1) {oma=1;}
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  
  for (int i=N-1; i>=0; i-=2) {
    cout << a[i] << " ";
  }
  for (int i=oma; i<N; i+=2) {
    cout << a[i];
    if (i<N-2) {
       cout << " ";
    }
  }
  cout << endl;
}
