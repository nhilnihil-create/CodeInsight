#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;	cin >> N;
  int a[110000];
  for (int i=0; i<N; i++)
    cin >>a[i] ;
  
  int odd=0;
  for (int i=0; i<N; i++) {
    if (a[i] %2 != 0)
      odd += a[i];
  }
    
    if (odd%2 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
