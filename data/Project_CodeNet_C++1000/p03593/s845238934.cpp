#include <bits/stdc++.h>

using namespace std;

int main(){
  int h, w;
  string s[109];
  map<char, int> mp;
  cin >> h >> w;
  for(int i=0;i<h;i++)cin >> s[i];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++)mp[s[i][j]]++;
  }
  int corner=4*(h/2)*(w/2);
  int center=(h-(h/2)*2)*(w-(w/2)*2);
  int cross=h*w-corner-center;
  while(corner>0){
    bool is_ok=false;
    for(auto& p: mp){
      int tmp=min(corner, p.second/4*4);
      if(tmp>0)is_ok=true;
      p.second-=tmp;
      corner-=tmp;
    }
    if(!is_ok){
      cout << "No" << endl;
      return 0;
    }
  }
  while(cross>0){
    bool is_ok=false;
    for(auto& p: mp){
      int tmp=min(cross, p.second/2*2);
      if(tmp>0)is_ok=true;
      p.second-=tmp;
      cross-=tmp;
    }
    if(!is_ok){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}


