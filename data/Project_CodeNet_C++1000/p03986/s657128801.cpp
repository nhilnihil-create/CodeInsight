# include <iostream>
# include <vector>
using namespace std;

int main(){
  string s;
  cin >> s;

  vector<char> stack;  
  for(int i=0; i<s.size(); i++){
    if(s[i] == 'S') stack.push_back(s[i]);
    else if(s[i] == 'T'){
      if(!stack.empty() && stack.back() == 'S') stack.pop_back();
      else stack.push_back(s[i]);
    }
  }

  cout << stack.size() << endl;
  return 0;
}