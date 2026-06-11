#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b; cin >> n >> a >> b;
  int c = a + b, num = 0, sumb = 0;
  string s; cin >> s;
  for(int i = 0; i < n; i++){
    if(s.at(i) == 'a' && num < c){
      num++; cout << "Yes" << endl;
    }
    else if(s.at(i) == 'b'){
      sumb++;
      if(num < c && sumb <= b){
        num++; cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }  
}  