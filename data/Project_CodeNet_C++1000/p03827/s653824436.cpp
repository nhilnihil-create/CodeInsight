#include <iostream>
#include <string>

using namespace std;

int main() {

  int n, g = 0, GG = 0;
  string p;
  cin >> n >> p;
  for(int i = 0;i < p.size();i++){
    if(p[i] == 'I'){
      g++;
    }else{
      g--;
    }
    GG = max(GG, g);
  }
  cout << GG;
  return 0;
}
