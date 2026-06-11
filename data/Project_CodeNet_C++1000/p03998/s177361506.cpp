#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  string sa,sb,sc;
  cin >> sa >> sb >> sc;
  
  sa += 'f'; sb += 'f'; sc += 'f';
  int a = 0, b = 0, c = 0;
  char turn = 'a';
  while(1){
    if(turn == 'a'){
      if(sa[a] == 'f'){
        cout << 'A' << endl;
        return 0;
      }
      turn = sa[a];
      a++;
    }else if(turn == 'b'){
      if(sb[b] == 'f'){
        cout << 'B' << endl;
        return 0;
      }
      turn = sb[b];
      b++;
    }else if(turn == 'c'){
      if(sc[c] == 'f'){
        cout << 'C' << endl;
        return 0;
      }
      turn = sc[c];
      c++;
    }
  }
}