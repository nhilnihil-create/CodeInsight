#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int sx, sy, tx, ty; cin >> sx >> sy >> tx >>ty;
  vector <char>ans;
  rep(i, tx-sx) ans.push_back('R');
  rep(i, ty-sy) ans.push_back('U');
  rep(i, tx-sx) ans.push_back('L');
  rep(i, ty-sy) ans.push_back('D');
  ans.push_back('L');
  rep(i, ty-sy+1) ans.push_back('U');
  rep(i, tx-sx+1) ans.push_back('R');
  ans.push_back('D');
  ans.push_back('R');
  rep(i, ty-sy+1) ans.push_back('D');
  rep(i, tx-sx+1) ans.push_back('L');
  ans.push_back('U');
  rep(i, ans.size()){
    cout << ans[i] << "";
  }
}
  
