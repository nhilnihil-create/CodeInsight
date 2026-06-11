#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  string S;
  cin >> S;
  int len = (int)(S.length());
  
  int unk = len;
  while (unk > 0){
    if (unk < 5){
      cout << "NO" << endl;
      exit(0);
    }
    
    if (S.substr(unk - 5, 5) == "dream" || S.substr(unk - 5, 5) == "erase"){
      unk -= 5;
      continue;
    }
    
    if (unk < 6){
      cout << "NO" << endl;
      exit(0);
    }
    
    if (S.substr(unk - 6, 6) == "eraser"){
      unk -= 6;
      continue;
    }
    
    if (unk < 7){
      cout << "NO" << endl;
      exit(0);
    }
    
    if (S.substr(unk - 7, 7) == "dreamer"){
      unk -= 7;
      continue;
    }
    else{
      cout << "NO" << endl;
      exit(0);
    }
  }
  
  cout << "YES" << endl;
}