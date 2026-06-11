#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  string s; cin >> s;

  map<char,int> mp;
  for(int i = 0; i < s.size(); i++){
    mp[s[i]]++;
    if(mp[s[i]] == 2){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
  return 0;
}
