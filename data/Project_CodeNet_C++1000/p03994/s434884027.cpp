#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using Graph = vector<vector<int>>;
const int INF = 1000000007;
int main(){
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  rep(i,n){
    if(s[i] == 'a')continue;
    int Abs = abs('z' - s[i]) + 1;
    if(Abs <= k){
      s[i] = 'a';
      k -= Abs;
    }
  }
  k %= 26;
  vector<char>al(26);
  rep(i,26)al[i] = 'a' + i;
  int now = 0;
  rep(i,26)if(al[i] == s[n - 1])now = i;
  rep(i,k){
    now++;
    now %= 26;
  }
  s[n - 1] = al[now];
  cout << s << endl;
  return 0;
}
