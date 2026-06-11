#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  vector<int>data(26,0);
  for(int i = 0;i < h;i++){
    string s;
    cin >> s;
    for(int j = 0;j < w;j++){
      data[s[j]-'a']++;
    }
  }
  int fc = 0,tc = 0,oc = 0;
  for(int i = 0;i < 26;i++){
    if(data[i]%2 == 1){
      oc++;
      data[i]--;
    }
    if(data[i]%4 == 0){
      fc += data[i]/4;
    }
    else{
      fc += data[i]/4;
      tc ++;
    }
  }
  if(fc >= (w/2)*(h/2)){
    tc += (fc-(w/2)*(h/2))*2;
    fc = (w/2)*(h/2);
  }
  else{
    cout << "No" << endl;
    return 0;
  }
  bool judge = false;
  if(w%2 == 0 && h%2 == 0){
    if(oc == 0 && tc == 0) judge = true;
  }
  else if(w%2 == 1 && h%2 == 0){
    if(oc == 0 && tc == h/2) judge = true;
  }
  else if(w%2 == 0 && h%2 == 1){
    if(oc == 0 && tc == w/2) judge = true;
  }
  else{
    if(oc == 1 && tc == w/2+h/2) judge = true;
  }
  if(judge) cout << "Yes" << endl;
  else cout << "No" << endl;
}
