#include <bits/stdc++.h>
using namespace std;

int main(){
  string w;
  cin >> w;
  set<char> a;
  for(int i = 0; i < w.size(); i++){
    a.insert(w.at(i));
  }
  for(auto value : a){
    int count = 0;
    for(int i = 0; i < w.size(); i++){
      if(value == w.at(i)){
        count++;
      }
    }
    if(count % 2 != 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
