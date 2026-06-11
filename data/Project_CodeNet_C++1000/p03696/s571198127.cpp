#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin>>N;
  string s;
  cin>>s;
  int cnt = 0;
  int mi = 0;
  for(int i = 0; i < N; i++) {
    if(s[i]=='(') cnt++;
    if(s[i]==')') {
      cnt--;
      chmin(mi,cnt);
    }
  }
  for(int i = 0; i < abs(mi);i++){
    cout<<'(';
  }
  cout<<s;
  for(int i = 0; i < cnt+abs(mi); i++){
    cout<<')';
  }
}