#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int n,m;
  cin >> n>>m;
  vector<int>a(m),b(m),c(n,1);
  vector<bool>d(n);
  d[0]=true;
  rep(i,m){
    cin>>a.at(i)>>b.at(i);
    a.at(i)--;
    b.at(i)--;
    c[a.at(i)]--;
    c[b.at(i)]++;
    if(d[a.at(i)]){
      d[b.at(i)]=true;
      if(c[a.at(i)]==0){
        d[a.at(i)]=false;
      }
    }
  }
  int ans=0;
  rep(i,n){
    if(d.at(i)){
      ans++;
    }
  }
  cout<<ans<<endl;  
}