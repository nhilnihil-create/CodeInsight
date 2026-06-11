#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  
  int res = 0, res1 = 0;
  for(int i=0; i<s.size(); ++i){
    if(s[i]=='a'){
      if(res<a+b){
        ++res; 
        cout << "Yes" << endl;
      }
      else cout << "No" << endl;
    }
    else if(s[i]=='b'){
      if(res<a+b && res1<b){
        ++res;
        ++res1; 
        cout << "Yes" <<endl;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }

  return 0;
}