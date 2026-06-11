#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <list>
using namespace std;

int main() {
  string a,b,c;
  cin >> a;
  cin >> b;
  cin >> c;

  int A=0,B=0,C=0;
  char now='a';
  for(int i = 0; i < (int)a.size() + (int)b.size() + (int)c.size(); ++i){
    if(now == 'a'){
      if(A == (int)a.size()){
        cout << 'A' << endl;
        break;
      }
      now = a[A];
      A++;
      continue;
    }
    if(now == 'b'){
      if(B == (int)b.size()){
        cout << 'B' << endl;
        break;
      }
      now = b[B];
      B++;
      continue;
    }
    if(now == 'c'){
      if(C == (int)c.size()){
        cout << 'C' << endl;
        break;
      }
      now = c[C];
      C++;
      continue;
    }
  }
}

