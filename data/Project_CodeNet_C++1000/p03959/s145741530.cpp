#include <bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
#define _GLIBCXX_DEBUG
using namespace std;
int64_t M = 1000000007;
int main(){
  int64_t n;
  cin >> n;
  vector<int64_t> t(n),a(n);
  rep(i,n){
    cin >> t[i];
  }
  rep(i,n){
    cin >> a[i];
  }
  vector<int64_t> th(n),ah(n);
  vector<bool> tdecided(n),adecided(n);
  rep(i,n){
    if(i == 0){
      th[i] = t[0];
      tdecided[0] = true;
    }else{
      th[i] = t[i];
      if(t[i-1] != t[i]){
        tdecided[i] = true;
      }
    }
  }
  invrep(i,n){
    if(i == n-1){
      ah[n-1] = a[n-1];
      adecided[n-1] = true;
    }else{
      ah[i] = a[i];
      if(a[i+1] !=a[i]){
        adecided[i] = true;
      }
    }
  }
  /*rep(i,n){
    cout << adecided[i] << tdecided[i] << endl;
  }*/
  bool failed = false;
  vector<int64_t> resh(n);
  vector<bool> decided(n);
  
  rep(i,n){
    if(tdecided[i] && adecided[i]){
      if(th[i] == ah[i]){
        resh[i] = th[i];
        decided[i] = true;
      }else{
        failed = true;
        break;
      }
    }else if(tdecided[i]){
      if(th[i] <= ah[i]){
        resh[i] = th[i];
        decided[i] = true;
      }else{
        failed = true;
        break;
      }
    }else if(adecided[i]){
      if(ah[i] <= th[i]){
        resh[i] = ah[i];
        decided[i] = true;
      }else{
        failed = true;
        break;
      }
    }else{
      resh[i] = min(th[i],ah[i]);
      decided[i] = false;
    }
  }
  /*rep(i,n){
    cout << decided[i] << " ";
  }
  cout << endl;
  rep(i,n){
    cout << resh[i] << " ";
  }*/
  if(failed){
    cout << 0 << endl;
  }else{
    int64_t res = 1;
    rep(i,n){
      if(!decided[i]){
        res = (res * resh[i])%M;
      }
    }
    cout << res << endl;
  }
        
      
  

      
  
}