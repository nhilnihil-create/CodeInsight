#include <bits/stdc++.h>
using namespace std;

int main(){
  string Sa,Sb,Sc;
  cin >> Sa >> Sb >> Sc;
  Sa += "e";
  Sb += "e";
  Sc += "e";
  int ia=1, ib=0, ic=0;
  char c = Sa[0];
  while(true){
    switch(c){
      case 'a':
        c = Sa[ia];
        ia++;
        if (c=='e'){
          cout << "A" << endl;
          return 0;
        }
        break;
      case 'b':
        c = Sb[ib];
        ib++;
        if (c=='e'){
          cout << "B" << endl;
          return 0;
        }
        break;
      case 'c':
        c = Sc[ic];
        ic++;
        if (c=='e'){
          cout << "C" << endl;
          return 0;
        }
        break;
    }
  }
  return 0;
}
        