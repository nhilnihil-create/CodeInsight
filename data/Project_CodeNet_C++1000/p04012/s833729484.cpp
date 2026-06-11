#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string w;
  cin >> w;

  sort(w.begin(), w.end());
  bool beauty = true;
  for(int i = 0; i < w.size(); i +=2){
    if(w[i] != w[i+1]) {
      beauty = false;
      break;
    }
  }
  if(beauty) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}