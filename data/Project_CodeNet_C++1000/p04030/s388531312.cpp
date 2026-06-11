#include <iostream>
#include <string>

using namespace std;
int main(){
  string s;
  cin >> s;

  string dsp;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '0' || s[i] == '1'){
      dsp.push_back(s[i]);
    } else if(dsp != "") {
      dsp.pop_back();
    }
  }
  cout << dsp << endl;
  return 0;
}
