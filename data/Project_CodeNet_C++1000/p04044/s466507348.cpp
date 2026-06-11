#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  vector<string> s;
  for(int i = 0; i < n; i++){
    string tmp;
    cin >> tmp;
    s.push_back(tmp);
  }
  sort(s.begin(), s.end());

  string output;
  for(int i = 0; i < n; i++){
    output = output + s[i];
  }

  cout << output << endl;
  return 0;
}