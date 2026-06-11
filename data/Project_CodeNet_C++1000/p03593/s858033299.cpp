#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[26];

void ext(){ cout <<"No" << endl; exit(0);}

int main(){
  int H,W; cin >> H >> W;
  
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      char a; cin >> a;cnt[a-'a']++;
    }
  }
  
  int mp1 = (H%2)*(W%2);
  
  int mp2 = 0;
  if( H%2 ){ mp2 += (W/2);}
  if( W%2 ){ mp2 += (H/2);}
  
  int mp4 = H*W-mp1-mp2;
  
  
  if( mp1){ 
   for(int i = 0; i < 26; i++){
     if( cnt[i] % 2){ cnt[i]--; break;}
   }
  }
  
  for(int i = 0; i < 26; i++){
    if( cnt[i] % 2 ){ ext();}
  }// 1mod4の判定
  
    int res = 0;
    for(int i = 0; i < 26; i++){
      if( cnt[i] % 4 == 2){ res++;}
    }
  
 
    if( res > mp2){ ext();} //2mod4の判定
  
  
  cout << "Yes" << endl;
  
  return 0;
}
    
    