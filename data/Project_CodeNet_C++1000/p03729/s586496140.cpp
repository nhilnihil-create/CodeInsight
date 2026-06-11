#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;

int main() {
  
  int a,b,c,d;
  string s,ss,sss;
  long long ans = 0;
  string anss = "";
  
  cin >> s >> ss >> sss;

  if(s[s.size()-1] == ss[0] && ss[ss.size()-1] == sss[0]) anss = "YES";
  else anss = "NO";
  
  cout << anss << endl;

}