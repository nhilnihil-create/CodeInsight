 #include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  if(s.size() > t.size()){
    for(int i = 0; i < t.size();++i){
      cout << s.at(i) << t.at(i);
    }
    cout << s.at(s.size()-1) << endl;
  } else if(s.size() < t.size()){
    for(int i = 0; i < s.size(); ++i){
      cout << s.at(i) << t.at(i);
    }
    cout << t.at(t.size()) << endl;
  } else {
    for(int i = 0; i < s.size(); ++i){
      cout << s.at(i) << t.at(i);
    }
    cout << endl;
  }
  
}
