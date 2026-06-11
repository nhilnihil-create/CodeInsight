#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	int n;
  cin >> n;
  string s;
  cin >> s;

  int rnum = 0;
  for(int i = 0; i < n; ++i){
    if(s[i] == '(') rnum++;
    else if(s[i] == ')' && rnum > 0) rnum--;
  }

  int lnum = 0;
  for(int i = n-1; i >= 0; --i){
    if(s[i] == ')') lnum++;
    else if(s[i] == '(' && lnum > 0) lnum--;
  }

  string ans = "";
  for(int i = 0; i < lnum; ++i){
    ans += '(';
  }
  ans += s;
  for(int i = 0; i < rnum; ++i){
    ans += ')';
  }

  cout << ans << endl;

	return 0;
}

