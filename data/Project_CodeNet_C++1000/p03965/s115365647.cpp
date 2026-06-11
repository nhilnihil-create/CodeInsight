#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))

int main(){
  string s;
  cin >> s;
  int ans = 0;
  int pnum = 0, gnum = 0;
  for(int i = 0; i < int(s.size()); i++){
    if(pnum == gnum){
      if(s[i] == 'p'){
        ans--;
        gnum++;
      }else{
        gnum++;
      }
    }
    else{
      if(s[i] == 'g'){
        ans++;
        pnum++;
      }else{
        pnum++;
      }
    }
  }
  cout << ans << endl;
}