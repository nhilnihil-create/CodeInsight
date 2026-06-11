#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
  string sa,sb,sc;
  cin >> sa >> sb >> sc;
  char turn  = 'a';
  while(true){
    if(turn == 'a'){
      if(sa == ""){
        cout << "A" << endl;
        return 0;
      }
      turn = sa.front();
      sa.erase(sa.begin());
      
    } 
    else if(turn == 'b'){
      if(sb == ""){
        cout << "B" << endl;
        return 0;
      }
      turn = sb.front();
      sb.erase(sb.begin());
      
    }
    else{
      if(sc == ""){
        cout << "C" << endl;
        return 0;
      }
      turn = sc.front();
      sc.erase(sc.begin());
      
    }
  }
  
}

