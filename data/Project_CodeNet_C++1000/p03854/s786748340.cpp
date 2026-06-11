#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main() {
  string s;
  cin >> s;
  int n=s.size();
  while(s.size()!=0){
    if(s.substr(max(0,n-5))=="dream"){
      n-=5;
      s.erase(n);
    }
    else if(s.substr(max(0,n-5))=="erase"){
      n-=5;
      s.erase(n);
    }
    else if(s.substr(max(0,n-7))=="dreamer"){
      n-=7;
      s.erase(n);
    }
    else if(s.substr(max(0,n-6))=="eraser"){
      n-=6;
      s.erase(n);
    }
    else{
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
