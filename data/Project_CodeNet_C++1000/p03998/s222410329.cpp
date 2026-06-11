#include <bits/stdc++.h>
using namespace std;
int main(){
  string Sa,Sb,Sc;
  char card;
  cin >> Sa >> Sb >> Sc;
  int a = 0,b = 0, c = 0;
  card = Sa.at(a);
  a++;
  cin >> Sa >> Sb >> Sc;
  while(1){
    switch(card){
      case 'a':
        if(Sa[a] =='\0'){
          cout << "A" <<endl;
          return 0;
        }
        else{
          card = Sa.at(a);
          a++;
        }
        break;
        
      case 'b':
        if(Sb[b] =='\0'){
          cout << "B" <<endl;
          return 0;
        }
        else{
          card = Sb.at(b);
          b++;
        }
        break;
        
      case 'c':
        if(Sc[c] =='\0'){
          cout << "C" <<endl;
          return 0;
        }
        else{
          card = Sc.at(c);
          c++;
        }
        break;
    }
  }
}
  
