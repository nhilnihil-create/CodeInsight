#include <bits/stdc++.h>
using namespace std;

int main() {
  string w;
  cin >> w;
  int c=0;
  for(int i=0; i < w.size() ; i++){
    for(int j=0; j < w.size() ; j++){
      if(w.at(i) == w.at(j)) c++;
    }
    if(c % 2 ==1){
      cout << "No" ;
      return 0;
    }
  }
  cout << "Yes" ;
}
