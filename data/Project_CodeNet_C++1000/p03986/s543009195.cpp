#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  string s;
  int n;
  cin >> s;
  n = s.length();
  int cur = 0;
  int ans = 0;
  stack<char> st;
  rep(i, n) {
    if(st.empty()) {
      st.push(s[i]);
    } else {
      char c = st.top();
      if (c == 'S' && s[i] == 'T') st.pop();
      else st.push(s[i]);
    }
  }
  cout << st.size() << endl;
}