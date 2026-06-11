#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  string s;
  vector<string> vec(h);
  rep(i,h)cin>>vec[i];
  rep(i,h*2){
    cout<<vec[i/2]<<endl;
  }
}