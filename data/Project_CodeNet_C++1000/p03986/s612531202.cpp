#include <iostream>

using namespace std;

int main() {

  int T = 0, S = 0;
  string n;
  cin >> n;
  for(int i = 0;i < n.size();i++){
    if(n[i] =='T'){
      if(S > 0){
        S--;
      }else{
        T++;
      }
    }else{
      S++;
    }
  }
  cout << S + T;
  return 0;
}
