#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  string s,t;
  cin >> s >> t;
  int q;
  cin >> q;
  vector<int> sa(s.length()+1),ta(t.length()+1);
  sa[0]=0;
  ta[0]=0;
  rep(i,s.length()){
    if(s[i]=='A') sa[i+1]=sa[i]+1;
    else sa[i+1]=sa[i];
  }
  rep(i,t.length()){
    if(t[i]=='A') ta[i+1]=ta[i]+1;
    else ta[i+1]=ta[i];
  }
  rep(i,q){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x=sa[b]-sa[a-1];
    int y=ta[d]-ta[c-1];
    if(((x+(b-a-x+1)*2)-(y+(d-c-y+1)*2))%3==0){
      cout << "YES" << endl;
      
    }
    else cout << "NO" << endl;
  }
}