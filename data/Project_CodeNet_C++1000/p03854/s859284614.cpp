#include <bits/stdc++.h>
using namespace std;

bool answer(string &s){
  if(s=="") return true;
  
  int l=s.size();
  if(s.at(l-1)=='m'&&s.at(l-2)=='a'&&s.at(l-3)=='e'&&s.at(l-4)=='r'&&s.at(l-5)=='d') return answer(s.erase(l-5));
  if(s.at(l-1)=='e'&&s.at(l-2)=='s'&&s.at(l-3)=='a'&&s.at(l-4)=='r'&&s.at(l-5)=='e') return answer(s.erase(l-5));
  if(s.at(l-1)=='r'&&s.at(l-2)=='e'&&s.at(l-3)=='s'&&s.at(l-4)=='a'&&s.at(l-5)=='r'&&s.at(l-6)=='e') return answer(s.erase(l-6));
  if(s.at(l-1)=='r'&&s.at(l-2)=='e'&&s.at(l-3)=='m'&&s.at(l-4)=='a'&&s.at(l-5)=='e'&&s.at(l-6)=='r'&&s.at(l-7)=='d') return answer(s.erase(l-7));
  return false;
}

int main() {
  string s;
  cin >> s;
  if(answer(s)) cout << "YES" << endl;
  else cout << "NO" << endl;
}
