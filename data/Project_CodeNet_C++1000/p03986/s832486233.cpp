#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string X;
  cin>>X;
  vector<int> ch;
  int cnt = 0;
  int l = X.size();
  rep(i,l){
    if(X[i]=='S') cnt++;
    if(X[i]=='T') cnt--;
    if(i==l-1) ch.push_back(cnt);
    else if(X[i]!=X[i+1]) {
      ch.push_back(cnt);
      cnt=0;
    }
  }
  int len = ch.size();
  int s = 0;
  rep(i,len){
    if(ch[i]<0) continue;
    s = ch[i];
    while(s>=0){
      if(i==len-1) break;
      i++;
      s+=ch[i];
    }
  }
  cout<<s*2<<endl;
}