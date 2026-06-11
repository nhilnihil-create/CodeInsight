#include <iostream>
using namespace std;
 
pair<int, int> getResult(const string &s){
  const size_t sSize = s.size();
  pair<int, int> range = {-1, -1};
  if(sSize < 2){
    return range;
  }
  if(sSize == 2){
    if(s[0] == s[1]){
      range.first = 1;
      range.second = 2;
    }
    return range;
  }
 
  for(int i = 0; i + 2 < sSize; i++){
    if((s[i] == s[i+1]) || (s[i] == s[i+2]) || (s[i+1] == s[i+2])){
      range.first = i + 1;
      range.second = i + 3;
      break;
    }
  }
  return range;
}
 
int main(){
  string s;
  cin >> s;
  pair<int, int> result = getResult(s);
  cout << result.first << " " << result.second << endl;
}