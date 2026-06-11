#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

//	vector<int> a(n);

  string s;

  cin >> s;

  int a,z;

  for(int i=0;i<s.length();i++ ){
    if(s[i]=='A'){
      a = i+1;
      for(int j=i;j<s.length();j++){
        if(s[j] == 'Z'){
          z = j+1;
        }
      }
      break;
    }
  }

//  cout << "a:" << a << " z:" << z << endl;
  cout << z-a+1 << endl;

}