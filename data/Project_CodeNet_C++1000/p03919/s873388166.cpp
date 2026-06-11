#include <bits/stdc++.h>
using namespace std;

int main(){
  int w,h,tmp;
  string s;
  cin >> w >> h;
  for(int i=0; i<w*h; i++){
    cin >> s;
    if(s=="snuke"){ 
      tmp = i;
      break;
    }
  }
  char x;
  x = 65+tmp%h;
  cout << x << 1+(tmp/h) << endl;
}