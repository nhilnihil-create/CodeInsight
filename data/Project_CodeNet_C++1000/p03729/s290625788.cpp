#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i < (int)(n);i++)

int main(){
   int n;
   string s,t,u;
   cin >> s >> t >> u;
   if (s[s.size()-1] == t[0] && t[t.size()-1] ==u[0]) cout << "YES" << endl;
   else cout << "NO" << endl; 
  
  return 0;
}

