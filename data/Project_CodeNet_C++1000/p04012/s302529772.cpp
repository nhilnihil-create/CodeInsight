#include <iostream>
#include <map>
using namespace std;

string getResult(const string &w){
  map<char, int> charCount;
  for(char c = 'a'; c <= 'z'; c++){
    charCount[c] = 0;
  }
 
  for(char c : w){
    charCount[c]++;
  }
  for(auto itr = charCount.begin(); itr != charCount.end(); itr++){
    if(itr->second % 2 != 0){
      return "No";
    }
  }
  return "Yes";
}

int main(){
  string w;
  cin >> w;
  string result = getResult(w);
  cout << result << endl;
}