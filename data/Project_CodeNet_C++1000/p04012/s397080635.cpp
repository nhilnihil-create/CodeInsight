#include <bits/stdc++.h>
using namespace std;
#define storpa ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
      storpa;
      bool p=true;
      string s;
      int a[101]{};
      cin >> s;
      for(int i=0; i<s.size(); i++){
        ++a[s[i]-'a'];
      }
      for(int i=0;i<=26; i++){
        if(a[i]%2!=0){
          p=false;
          break;
        }
      }
      if(p==true){
        cout << "Yes";
      }
      else cout << "No";
}
