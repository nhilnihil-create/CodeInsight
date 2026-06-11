#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli H,W,h,w;

int main(){
  cin >> H >> W >> h >> w;
  if(H%h == 0 && W%w == 0){
    cout << "No" << endl;
    return 0;
  }
  if(W%w != 0){
    vll s(W+1);
    for(lli i = w;i <= W;i += w){
      s[i] = s[i-w]-1;
    }
    s[W] = 1;
    for(lli i = W-w;i >= 0;i -= w){
      s[i] = s[i+w]+1;
    }
    for(lli i = 0;i <= W-w;i++){
      if(s[i] <= s[i+w]) s[i+w] = s[i]-1;
    }
    cout << "Yes" << endl;
    for(lli i = 0;i < H;i++){
      for(lli j = 0;j < W;j++){
        cout << s[j+1]-s[j] << (j == W-1 ? "\n" : " ");
      }
    }
  }else{
    vll s(H+1);
    for(lli i = h;i <= H;i += h){
      s[i] = s[i-h]-1;
    }
    s[H] = 1;
    for(lli i = H-h;i >= 0;i -= h){
      s[i] = s[i+h]+1;
    }
    for(lli i = 0;i <= H-h;i++){
      if(s[i] <= s[i+h]) s[i+h] = s[i]-1;
    }
    cout << "Yes" << endl;
    for(lli i = 0;i < H;i++){
      for(lli j = 0;j < W;j++){
        cout << s[i+1]-s[i] << (j == W-1 ? "\n" : " ");
      }
    }
  }

  return 0;
}
