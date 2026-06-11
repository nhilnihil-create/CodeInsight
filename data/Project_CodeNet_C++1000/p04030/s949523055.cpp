#include <iostream>
using namespace std;

string getResult(const string &s){
  const size_t sSize = s.size();
  string result = "";
  for(int i = 0; i < sSize; i++){
    if(s[i] == 'B'){
      result.pop_back();
    }else{
      result.push_back(s[i]);
    }
  }
  return result;
}

int main(){
  string s;
  cin >> s;
  string result = getResult(s);
  cout << result << endl;
}