#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main(){
  string sa,sb,sc;
  cin >> sa >> sb >> sc;

  int a = 0, b = 0, c = 0;
  char now = 'a';
  char winner;

  while(true){
    if(now == 'a'){
      if(a == sa.size()){
        winner = 'A';
        break;
      }
      now = sa[a];
      a++;
    }else if(now == 'b'){
      if(b == sb.size()){
        winner = 'B';
        break;
      }
      now = sb[b];
      b++;
    }else if(now == 'c'){
      if(c == sc.size()){
        winner = 'C';
        break;
      }
      now = sc[c];
      c++;
    }
  }
  cout << winner;
  cout << "\n";
  return 0;
}