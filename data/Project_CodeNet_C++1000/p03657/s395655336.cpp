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
  
  int ans = 0;
  string anss = "";
  
  int ab [] = {0 , 1 , 3 , 1 , 2 , 1 , 2 , 1 , 1 , 2 , 1 , 2 , 1};
  
  cin >> a >> b >> c;

  int result3 = std::max({a, b, c});
  
  if (a%3 == 0) anss = "Possible";
  else if (b%3 == 0) anss = "Possible";
  else if ((a+b)%3 == 0) anss = "Possible";
  else anss = "Impossible";
  
  cout << anss << endl;

}