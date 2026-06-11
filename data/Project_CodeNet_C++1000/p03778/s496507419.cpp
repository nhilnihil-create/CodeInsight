#include <bits/stdc++.h>
using namespace std;

int main() {
  int w,a,b;
  int kekka;
  cin >> w >> a >> b;
  
  if(a <= b){
    cout << max(0,b - (a+w));
  }else{
    cout << max(0,a - (b+w));
  }
}
