#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<pair<int,int>>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int l = 0,r = 0;
  string tmp = s;
  rep(i,n){
    if(tmp[i] == '('){
      REP(j,i + 1,n){
        if(tmp[j] == ')'){
          tmp[i] = 'x',tmp[j] = 'x';
          break;
        }
      }
    }
  }
  rep(i,n){
    if(tmp[i] == '(')r++;
    else if(tmp[i] == ')')l++;
  }
  rep(i,l)cout << '(';
  cout << s;
  rep(i,r)cout << ')';
  cout << endl;
  return 0;
}
