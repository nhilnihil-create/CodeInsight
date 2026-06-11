#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  string s; 
  cin >> s;
  int n = s.size();
  int N=0, W=0, S=0, E=0;
  if(n==1){
    cout << "No";
    return 0;
  }
  for(int i=0; i<n; ++i){
    if(s[i]=='N') N=1;
    if(s[i]=='W') W=1;
    if(s[i]=='S') S=1;
    if(s[i]=='E') E=1;
  }
  int res = N + W + S + E;
  if(N==1 && S==0) cout << "No";
  else if(N==0 && S==1) cout << "No";
  else if(W==1 && E==0) cout << "No";
  else if(W==0 && E==1) cout << "No";
  else cout << "Yes";
}