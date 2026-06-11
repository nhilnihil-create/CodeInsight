#include <bits/stdc++.h>
using namespace std;
int main(){
  int H,W,h,w;
  cin >> H >> W;
  string s;
  int i=0;
  while (i < H*W){
    cin >> s;
    if (s=="snuke") break;
    i++;
  }
  h = i/W+1;
  w = i-(h-1)*W+1;
  char p = 'A';
  p = p - 1 + w;
  cout << p << h;
}