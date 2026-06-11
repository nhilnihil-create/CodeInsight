#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int main(){
  int H,W,D; cin>>H>>W>>D;
  int d=D*2;
  rep(i,H){
    string ans="";
    rep(j,W){
      int r=(i+j)%d, c=((i-j)%d+d)%d;
      if(r<D){
        if(c<D) ans+="R";
        else ans+="Y";
      }else{
        if(c<D) ans+="G";
        else ans+="B";
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
