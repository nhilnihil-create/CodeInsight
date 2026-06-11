#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int mod=1000000007;
  int n,m,k;
  cin >> n>>m>>k;
  
    bool ex=false;
    rep(i,n+1){
      rep(j,m+1){
        if(i*j+(n-i)*(m-j)==k){
          ex=true;
        }
      }
    }
    if(ex){
      cout<<"Yes"<<endl;
    }
    else{
      cout<<"No"<<endl;
    }
  
}