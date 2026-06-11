#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h,w;
  cin>>h>>w;
  char pic[w][h];
  rep(i,h)rep(j,w){
    cin>>pic[j][i];
  }
  rep(i,h){
    rep(tmp,2){
      rep(j,w){
        cout<<pic[j][i];
      }
      cout<<endl;
    }
  }
}