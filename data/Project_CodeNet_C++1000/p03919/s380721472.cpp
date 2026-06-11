#include <string>
#include <iostream>
using namespace std;

int main(){
  int h, w; cin >> h >> w;
  string s;
  for(int i=0; i<h*w; i++){
    cin >> s;
    if(s == "snuke"){
      cout << char('A' + i%w) << i/w + 1 << endl;
    }
  }
  return 0;
}