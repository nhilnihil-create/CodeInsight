#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  string a,b,c;
  cin >> a >> b >> c;
  int asize=a.size(),bsize=b.size(),csize=c.size();
  int acnt=0,bcnt=0,ccnt=0;
  char now = 'a';
  
  while(true){
    if(now == 'a'){
      if(acnt == asize){
        cout << "A" << endl;
        break;
      }else{
        now = a[acnt];
        acnt++;
      }
    }else if(now == 'b'){
      if(bcnt == bsize){
        cout << "B" << endl;
        break;
      }else{
        now = b[bcnt];
        bcnt++;
      }
    }else if(now == 'c'){
      if(ccnt == csize){
        cout << "C" << endl;
        break;
      }else{
        now = c[ccnt];
        ccnt++;
      }        
    }
  }
  
  return(0);
}