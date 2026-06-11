# include <bits/stdc++.h>
using namespace std;
 
# define ll long long
 
int countSteps(string s, char c){
  s = c + s + c;
  int prevPos = 0;
  int result = 0;
  for(int i=1; i<s.size(); i++){
    if(s[i] == c){
      result = max(result, i - prevPos - 1);
      prevPos = i; 
    }
  }
  return result;
}
 
int main(){
 
  string s;
  cin >> s;
  int ans = 1e9;
  for(char c : s){
    ans = min(ans, countSteps(s, c));
  }
  cout << ans << endl;
  
  return 0;
} 
 