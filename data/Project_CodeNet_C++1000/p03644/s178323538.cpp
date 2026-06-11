#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
  cin >> n;
  if(n>=1 && n<2)cout << 1 << endl;
  if(n>=2 && n<4)cout << 2 << endl;
  if(n>=4 && n<8)cout << 4 << endl;
  if(n>=8 && n<16)cout << 8 << endl;
  if(n>=16 && n<32)cout << 16 << endl;
  if(n>=32 && n<64)cout << 32 << endl;
  if(n>=64 && n<=100)cout << 64 << endl;
}