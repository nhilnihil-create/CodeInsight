#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n;
  string s;
  cin >> n >> s;
  int x=0, mx =0;
  for(int i=0; i<n; ++i){
    if(s[i]=='I') ++x;
    else --x;
    mx = max(mx, x);
  }

  cout << mx << endl;
  return 0;
}