#include <bits/stdc++.h>
using namespace std;

string s;
int q;
vector<string> a = {"dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"};

void pei(int x){
  if(s.size() > x){
    for(int i = 0; i < 6; i++){
      int y = a[i].size();
      if(s.substr(x, y) == a[i]){
        pei(x + y);
        return;
      }else if(i == 5){
        q = 1;
        return;
      }
    }
  }else{
    if(s.size() != x){q = 1;}
    return;
  }
}

int main(){
  cin >> s;
  q = 0;
  pei(0);
  if(q == 0){cout << "YES" << endl;}
  else{cout << "NO" << endl;}
  return 0;
}
