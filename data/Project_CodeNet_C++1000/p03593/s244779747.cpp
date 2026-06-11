#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w;
  cin >> h >> w;
  vector<int>alp(26);
  rep(i,0,h){
    string s;
    cin >> s;
    rep(j,0,w) alp[s[j]-'a']++;
  }
  int ac4 = 1,ac2 = 0,ac1 = 0;
  if(h%2 != 0) ac4 *= h-1;
  else ac4 *= h;
  if(w%2 != 0) ac4 *= w-1;
  else ac4 *= w;
  ac4 /= 4;
  
  if(h%2 == 1) ac2 += w/2;
  if(w%2 == 1) ac2 += h/2;
  
  if(h%2 == 1 && w%2 == 1) ac1 = 1;
  
  int c4 = 0,c2 = 0,c1 = 0;
  rep(i,0,26){
    if(alp[i] >= 4){
      if(c4+alp[i]/4 > ac4){
        alp[i] -= (ac4-c4)*4;
        c4 = ac4;
      }
      else{
        c4 += alp[i]/4;
        alp[i] %= 4;
      }
    }
  }
  rep(i,0,26){
    if(alp[i] >= 2){
      if(c2+alp[i]/2 > ac2){
        alp[i] -= (ac2-c2)*2;
        c2 = ac2;
      }
      else{
        c2 += alp[i]/2;
        alp[i] %= 2;
      }
    }
  }
  rep(i,0,26) c1 += alp[i];
  if(c4 == ac4 &&(c2 == ac2 && c1 == ac1)) cout << "Yes" << endl;
  else cout << "No" << endl;
}