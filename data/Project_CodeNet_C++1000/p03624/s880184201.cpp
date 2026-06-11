#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s; 
  cin >> s;
  vector<bool> a(26);
  for(int i=0; i<26; ++i) a[i] = false;

  for(int i=0; s[i]!='\0'; ++i){
    a[s[i] - 'a'] = true;
  }
  for(int i=0; i<26; ++i){
    if(a[i]==false){
      cout << (char)(i+'a') << endl;
      return 0;
    }
  }
  cout << "None" << endl;
  return 0;
}