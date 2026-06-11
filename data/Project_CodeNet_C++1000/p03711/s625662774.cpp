#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin,(x).end()

int main(){
  //グループ0,1,2に各自割り振る
  vector<int> g{0,2,0,1,0,1,0,0,1,0,1,0,2};
  
  int x,y;
  cin >> x >> y;
  if(g[x-1] == g[y-1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}