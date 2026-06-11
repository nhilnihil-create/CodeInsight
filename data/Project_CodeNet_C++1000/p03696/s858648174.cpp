#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N; cin >> N;
  string S; cin >> S;
  string Sdash = S;
  while(Sdash.find("()") != string::npos){
  	Sdash.erase(Sdash.find("()"), 2);
  }
  ll left, right = 0;
  for (char c : Sdash) {
  	if (c == ')') right++;
    else break;
  }
  left = Sdash.size() - right;
  rep(i, 0, left) {
    S = S + ')';
  }
  rep(i, 0, right) {
  	S = '(' + S;
  }
  cout << S << endl;
}