#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26];

void ext(){ cout << "No" << endl; exit(0);}

int main(){

  int H,W; cin >> H >> W;
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      char c; cin >> c; cnt[c-'a']++;
    }
  }
  
  
  if((H*W)%2 == 1){
    for(int i = 0; i < 26; i++){
      if(cnt[i]%2 == 1){ cnt[i]--; break;}
    }
  }
  
  for(int i = 0; i < 26; i++){ if(cnt[i]%2 == 1){ ext();}}
  
  int g2 = 0;
  
  if(H%2 == 1){ g2 += W/2;}
  if(W%2 == 1){ g2 += H/2;}
  
  g2 *= 2;
  
  int m2 = 0;
  
  for(int i = 0; i < 26; i++){
    m2 += cnt[i]%4; // ここでcnt[i]%4は0か2しかありえないことに注意
  }
  
  
  if( m2 > g2){ ext();}
  
  cout << "Yes" << endl; 
  
  return 0;
}
