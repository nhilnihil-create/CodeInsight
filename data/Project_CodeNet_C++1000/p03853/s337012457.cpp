#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int h, w;
  cin >> h >> w;

  vector<string> C;
  for(int i = 0; i < h; i++) {
    string tmp;
    cin >> tmp;
    C.push_back(tmp);
  }
  for(int i= 0; i < h; i++) {
    cout << C[i] << endl;
    cout << C[i] << endl;
  }
  return 0;
}
