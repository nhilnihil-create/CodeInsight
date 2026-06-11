#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n);i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
  int h, w;
  cin >> h >> w;
  map<char, int> mp;
  set<char> st;
  vector<vector<char>> v(h, vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> v[i][j];
      mp[v[i][j]]++;
      st.insert(v[i][j]);
    }
  }
  vector<int> v1;
  if (h % 2 == 0 && w % 2 == 0)
  {
    rep(i,h/2){
      rep(j,w/2){
        v1.push_back(4);
      }
    }
  }
  else if (h % 2 == 1 && w % 2 == 1)
  {
    rep(i,h/2){
      rep(j,w/2){
        v1.push_back(4);
      }
    }
    rep(i,h/2){
      v1.push_back(2);
    }
    rep(i,w/2){
      v1.push_back(2);
    }
    v1.push_back(1);
  }
  else if(h % 2 == 1 && w %2 == 0)
  {
    rep(i,w/2){
      rep(j,h/2){
        v1.push_back(4);
      }
    }
    rep(i,w/2){
      v1.push_back(2);
    }
  }
  else if (w % 2 == 1 && h % 2 == 0)
  {
    rep(i, h / 2)
    {
      rep(j, w / 2)
      {
        v1.push_back(4);
      }
    }
    rep(i, h / 2)
    {
      v1.push_back(2);
    }
  }
  vector<int> v2;
  for(auto e:st){
    v2.push_back(mp[e]);
  }
  reverse(v2.begin(),v2.end());
  bool flag = true;
  rep(i,v1.size()){
    bool flag2 = false;
    rep(j, v2.size())
    {
      if (v2[j] >= v1[i])
      {
        v2[j]-=v1[i];
        flag2 = true;
        break;
      }
    }
    if(!flag2){
      flag = false;
      break;
    }
  }
  if(flag){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}