# include <iostream>
# include <string>
using namespace std;

bool allTheSame(string s){
  char c = s[0];
  for(int i=0; i<s.size(); i++)
    if(s[i] != c) return false;
  return true;
}

string process(string t, char ch){
  string result = "";
  for(int i=0; i<t.size()-1; i++){
    if(t[i] == ch || t[i+1]==ch) result += ch;
    else result += t[i];
  }
  return result;
}

int main(){
  string s;
  cin >> s;

  int ans = 1e6;
  for(char ch='a'; ch<='z'; ch++){
    string t = s;

    int cnt = 0;
    while(!allTheSame(t)){
      string result = process(t, ch);
      t = result;
      cnt++;
      if(t == s){
        cnt = 1e6;
        break;
      }
    }

    ans = min(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}