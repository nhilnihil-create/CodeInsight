#include <bits/stdc++.h>
using namespace std;

int main() {
  double n,c=0;
  int d=0;
  cin >> n;
  
  
  vector<int> a(n);
  for(int i=0 ; i < n; i++){
    cin >> a.at(i);
    c += a.at(i);
  }
  c = round(c / n);
  sort(a.begin(),a.end());
  for(int i=0; i < n ; i ++){
    d += (a.at(i) - c ) * (a.at(i) - c );
  }
  cout << d ;
}
