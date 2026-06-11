#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0; i<n; ++i){
    for(int j=0; j<n; ++j){
      if(i==j) break;
      if(s[i]==s[j]){
        cout << "no" << endl;
        return 0;
      }
    }
  }

  cout << "yes" << endl;

  return 0;
}