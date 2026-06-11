#include<bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  for(int i = 1 ; i <= h ; i++){
    bool flag = false;
    for(int j = 0 ; j < w ; j++){
      string s;
      cin >> s;
      if(s == "snuke"){
        char c = 'A' + j;
        cout << c << i << endl;
        flag = true;
        break;
      }
    }
    if(flag){
      break;
    }
  }
  return 0;
}