#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAXs
#define INFL LLONG_MAX
typedef long long ll;
using namespace std;
int main(){
  string a,b,c; cin >> a >> b >> c;
  int la = a.size(),lb = b.size(),lc = c.size();
  int aa = 0,bb = 0,cc = 0;

  char now = 'a';

  while(true){

    if(now=='a'){
      if(la==0){
        puts("A");
        return 0;
      }
      now = a.at(aa);
      la--;
      aa++;

    }else if(now=='b'){
      if(lb==0){
        puts("B");
        return 0;
      }
      now = b.at(bb);
      lb--;
      bb++;
    }else if(now=='c'){
      if(lc==0){
        puts("C");
        return 0;
      }
      now = c.at(cc);
      lc--;
      cc++;
    }
  }
}
