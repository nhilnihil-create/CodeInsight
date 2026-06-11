# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

# define ll long long

int main(){
 
  string S;
  cin >> S;
  vector<char> stack;
  
  for(int i=0; i<S.size(); i++){
    if(S[i] == 'S') stack.push_back(S[i]);
    else {
      if(!stack.empty() && stack.back() == 'S') stack.pop_back();
      else stack.push_back(S[i]);
    }
  }
  
  cout << stack.size() << endl;
  return 0;
} 

