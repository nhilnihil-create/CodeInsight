#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,start,end) for(int i=start;i<=end;i++)
const int INF = 1001001001;
using namespace std;
typedef long long ll;

bool check(char c, string s){
  bool res = true;
  rep(i, s.length()){
    if(s[i] != c) res = false;
  }
  return res;
}

int main()
{
  string s;
  cin >> s;
  int res = INF;

  for(char c = 'a'; c <= 'z'; c++) {
    auto it = find(s.begin(),s.end(), c);
    if(it==s.end()) continue;
    string S = s;
    int num = 0;
    bool isAllC = check(c, S);
    while(!isAllC){
      string ss;
      rep(i, S.length()-1){
        if(S[i] == c || S[i+1] == c) {
          ss += c;
        } else {
          ss += S[i];
        }
      }
      S = ss;
      num++;
      isAllC = check(c, S);
    }
    res = min(res, num);
  }

  cout << res << endl;
}
