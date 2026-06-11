#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string brackets;
  cin >> N >> brackets;
  
  int cumsum= 0;
  int min_neg= 0;
  for(auto c:brackets){
    if(c=='('){
      cumsum++;
    }
    else{
      cumsum--;
      min_neg= min(min_neg, cumsum);
    }
  }
  
  string prefix= string(abs(min_neg), '(');
  string suffix= string(cumsum- min_neg, ')');

  string ans= prefix + brackets + suffix; 

  cout << ans << endl;
}