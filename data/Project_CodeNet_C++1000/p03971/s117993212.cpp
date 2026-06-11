#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  
  int all = 0, cntb = 0;
  for(int i = 0; i < n; i++){
    if(all < a+b){
      if(s.at(i) == 'a'){
        cout << "Yes" << endl;
        all++;
      }
      else if(s.at(i) == 'b'){
        if(cntb < b){
          cout << "Yes" << endl;
          all++, cntb++;
        }
        else cout << "No" << endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }
}