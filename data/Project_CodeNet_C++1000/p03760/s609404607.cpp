#include<bits/stdc++.h>
using namespace std;

int main(){
  string s,t;
  cin >> s >> t;
  if(s.size() > t.size()){
    for(int i = 0; i < t.size(); i++){
      cout << s[i] << t[i];
    }
    cout << s[s.size() - 1] << endl;
    return 0;
  }else{
    for(int i = 0; i < t.size(); i++){
      cout << s[i] << t[i];
    }
    cout << endl;
    return 0;
  }
}
