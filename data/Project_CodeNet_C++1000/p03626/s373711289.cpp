#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long MOD = 1000000007;

int main() {
  int n;cin>>n;
  string s;cin>>s;
  vector<int> an;
  rep(i,n-1) {
    if (s[i]==s[i+1]) {an.push_back(2);i++;}
    else an.push_back(1);
  }
  if (n==1) an.push_back(1);
  else if (s[n-1]!=s[n-2]) an.push_back(1);
  
  //rep(i,an.size()) cout << an[i]<<" ";cout<<endl;
  
  long cnt; if (an[0]==1) cnt=3; else cnt=6;
  rep(i,an.size()-1) {
    if (an[i+1]==1) {
      if (an[i]==1) {
        cnt = (cnt * 2) % MOD;
        //cout<<"#11"<<endl;
      } 
      //else cout<<"#21"<<endl;
    } else {
      if (an[i]==1) {
        cnt = (cnt * 2) % MOD;
        //cout<<"#12"<<endl;
      } else {
        cnt = (cnt * 3) % MOD;
        //cout<<"#22"<<endl;
      }
    }
  }
  cout << cnt;
  
}
