#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define ssort(a) sort(a.begin(), a.end())
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  string s;
  cin >>s;
  int lnum=0, rnum=0;
  rep(i, n){
    if(s[i]=='('){
      lnum++;
    } else {
      if(lnum>0){
        lnum--;
      } else {
        rnum++;
      }
    }
  }
  int lnum2=0, rnum2=0;
  for(int i=n-1; i>=0; i--){
    if(s[i]==')'){
      rnum2++;
    } else {
      if(rnum2>0){
        rnum2--;
      } else {
        lnum2++;
      }
    }
  }
  rep(i, rnum){
    s='('+s;
  }
  rep(i, lnum2){
    s=s+')';
  }
  cout << s << endl;
  return 0;
}
