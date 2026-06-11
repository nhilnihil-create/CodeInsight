#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void){
  int h,w;
  string str;
  
  cin >> h >> w;
  
  for(int i = 0 ; i < h ; i++){
    for(int j = 0 ; j < w ; j++){
      cin >> str;
      if(str == "snuke"){
        cout << char('A' + j) << i+1 << endl;
      }
    }
  }
  return 0;
}