#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
    cin >> s;
    string t = "abcdefghijklmnopqrstuvwxyz";
    int ans = 0;
    for(int i=0;i<t.size();i++){
      int count = 0;
      for(int j=0;j<s.size();j++){
        if(t[i]==s[j]){
          count++;
        }
      }
      if(count == 0){
        cout << t[i] << endl;
        ans = 1;
        break;
      }
    }
    if(ans == 0){
      cout << "None" << endl;  
    }
}