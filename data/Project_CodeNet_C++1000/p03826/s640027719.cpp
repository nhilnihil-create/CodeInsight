#include <bits/stdc++.h>
using namespace std;

int main() {
  int fH,fW;
  int sH,sW;
  int fArea,sArea;
  
  cin >> fH >> fW >> sH >> sW;
  
  fArea = fH * fW;
  sArea = sH * sW;
  
  if(fArea >= sArea) cout << fArea;
  else cout << sArea;
}
