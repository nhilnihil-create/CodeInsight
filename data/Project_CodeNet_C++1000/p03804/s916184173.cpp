#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m; //n>m

  vector<vector<char>> pica(n,vector<char>(n));
  vector<vector<char>> picb(m,vector<char>(m));

  rep(i,n)rep(j,n) cin >> pica.at(i).at(j);
  rep(i,m)rep(j,m) cin >> picb.at(i).at(j);

  bool flag=true;
  rep(i,n-m+1){
    rep(j,n-m+1){
      flag = true;
      rep(k,m){
        rep(l,m){
          if(pica.at(i+k).at(j+l)!=picb.at(k).at(l)){flag=false; break;}
        }
        if(!flag) break;
      }
      if(flag) break;
    }
    if(flag) break;
  }

  if(flag) cout << "Yes";
  else cout << "No";

  
}