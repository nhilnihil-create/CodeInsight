#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n = (s.size()+1)/2;
  vector<char> ans(n);
  int j = 0;
  for(int i = 0; i < s.size(); i+=2){
    ans.at(j) = s.at(i);
    j++;
  }
  for(int i = 0; i < n; i++){
    cout << ans.at(i);
  }
  return 0;
}