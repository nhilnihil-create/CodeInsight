#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  int K;
  cin>>s>>K;
  int l = s.size();
  vector<int> v(l);
  rep(i,l){
    v[i]=s[i]-'a';
  }
  rep(i,l){
    if(v[i]==0&&i!=l-1)continue;
    if(K>=26-v[i]) {
      K-=(26-v[i]);
      v[i]=0;
    }
    if(K!=0&&i==l-1) {
      v[i]+=K;
      v[i]%=26;
    }
  }
  for(auto x:v){
    char c = 'a'+x;
    cout<<c;
  }
  cout<<endl;
}