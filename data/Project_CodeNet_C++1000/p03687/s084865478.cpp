#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;
int main(){
  string s; cin >> s;
  int n = s.size();
  int ans = INF;

  for(int c='a';c<='z';c++){
    bool ok = true;
    string str = s;
    rep(i,str.size()){
      if(str.at(i)!=c) ok = false;
    }

    if(ok){
      puts("0");
      return 0;
    }

    int num = str.size();

    while(true){
      ok = true;
      rep(i,num-1){
        if(str.at(i)==c || str.at(i+1)==c){
          str.at(i) = c;
        }else{
          ok = false;
        }
      }

      num--;

      if(ok){
        ans = min(ans,n - num);
        break;
      }
    }
  }

  cout << ans << endl;
}
