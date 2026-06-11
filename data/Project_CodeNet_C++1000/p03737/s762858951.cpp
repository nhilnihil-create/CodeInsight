#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  string s,t,u;
  cin >> s >> t >> u;
  int slide = 'A' - 'a';
  char S = s[0] + slide;
  char T = t[0] + slide;
  char U = u[0] + slide;
  cout << S << T << U << endl;
}