#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  
  if(b<a){
    int tmp=a;
    a=b;
    b=tmp;
  }
  
  cout << max(0, b-(a+W)) << endl;
}