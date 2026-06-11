#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int a,b,c,d;
  string s;
  long long ans = 0;
  
  cin >> a >> b;

  if(a == b) s = "Draw";
  else if(a == 1 || a > b && b != 1) s = "Alice";
  else s = "Bob";
  
  cout << s << endl;

}