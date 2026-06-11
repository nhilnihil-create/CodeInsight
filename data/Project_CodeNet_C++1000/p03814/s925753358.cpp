#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  string s;
  cin >> s;
  int hazime = 0;
  int saigo = 0;
  rep(i,s.size()){
   if(s[i] == 'A') {
     hazime = i;
     break;
   }
  }
   for(int i = s.size();i>0;i--){
     if(s[i] == 'Z'){
       saigo = i;
       break;
     }
  }
    cout << saigo - hazime + 1 << endl;
}
