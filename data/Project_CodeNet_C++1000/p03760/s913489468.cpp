#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main() {
  string o, e;
  cin >> o >> e;
  int os = o.size();
  int es = e.size();
  if(os == es){
    for(int i = 0; i < es; i++){
      cout << o[i] << e[i];
    }
    cout << endl;
    return 0;
  }

  else if(os = es + 1){
    for(int i = 0; i < es; i++){
      cout << o[i] << e[i]; 
    }
    cout << o[es] << endl;
    return 0;
  }
  return 0;
}
