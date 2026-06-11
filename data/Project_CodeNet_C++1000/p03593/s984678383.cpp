#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main(){
  ll h,w;
  cin >> h >> w;
  vector<ll>alp(26);
  for(int i=0; i<h*w; i++){
    char a;
    cin >> a;
    alp[a-'a']++;
  }
  ll one=0,two=0,four=0;
  if(h%2 && w%2)one=1;
  if(h%2)two+=w/2;
  if(w%2)two+=h/2;
  four=(h*w-two*2-one)/4;

  for(int i=0; i<26; i++){
    while(alp[i]>=4){
      if(four==0) break;
      four--;
      alp[i]-=4;
    }
  }
  
  for(int i=0; i<26; i++){
    while(alp[i]>=2){
      if(two==0) break;
      two--;
      alp[i]-=2;
    }
  }
  
  for(int i=0; i<26; i++){
    while(alp[i]>=1){
      if(one==0) break;
      one--;
      alp[i]-=1;
    }
  }
  
  if(!four && !two && !one) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}
  
  
  
