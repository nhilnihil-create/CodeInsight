#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>

using namespace std;

int main(){
  int i=0;
  string s;
  stringstream ss;
  vector<int> A;
  cin >> s;
  for(char c:s){
    if(i%2 == 0){
      ss << c;
    }
    i++;
  }
  cout << ss.str() << endl;

  return 0;
}
