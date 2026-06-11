#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vvint vector<vector<int>>
#define vstring vector<string>
#define vdouble vector<double>
#define vll vector<ll>:
#define vbool vector<bool>
#define INF 1101010101010101010
#define MOD 1000000007
#define int long long
using P = pair<int,int>;

signed main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x = 0;
  int left = 0;
  int right = 0;
  rep(i,n){
    if(s[i] == '('){
      x++;
    }
    if(s[i] == ')'){
      if(x > 0) x--;
      else{
        left++;
      }
    }
  }
  rep(i,left) cout << '(';
  cout << s;
  rep(i,x) cout << ')';
}
