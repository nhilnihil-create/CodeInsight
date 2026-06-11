#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h,w,n;cin>>h>>w>>n;
  int an[n];rep(i,n)cin>>an[i];
  int ni = 0;
  rep(i,h){
    int sn[w];
    rep(j,w){
      an[ni]--;
      sn[j] = ni+1;
      if (an[ni] == 0) ni++;
    }
    if (i%2==1) reverse(sn,sn+w);
    cout << sn[0];
    rep(i,w-1) cout << " " << sn[i+1]; 
    cout << endl;
  }
}
