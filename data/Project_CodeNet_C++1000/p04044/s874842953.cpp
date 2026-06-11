#include<bits/stdc++.h>
#define PI 3.141592653589
using namespace std;
using ll = long long;

template<typename T_char>
T_char ToUpper(T_char cX){return toupper(cX);}

int main(){
  int n, l;
  cin >> n >> l;

  vector<string> s(n);
  for(int i=0; i<n; ++i) cin >> s[i];


  sort(s.begin(), s.end());

  for(int i=0; i<n; ++i) cout << s[i];
}