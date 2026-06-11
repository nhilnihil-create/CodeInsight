#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;cin >> h >> w;
  vector<int> c(26);
  for(int i=0;i<h;i++){
    string s;cin >> s;
    for(int j=0;j<w;j++){
      c[s[j]-'a']++;
    }
  }
  if(h%2==0&&w%2==0){
    for(int i=0;i<26;i++){
      if(c[i]%4!=0){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
  else{
    int x,y,z;
    if(h%2==1&&w%2==1){
      x=1,y=h/2+w/2,z=(h/2)*(w/2);
      for(int i=0;i<26;i++){
        if(c[i]%4==1||c[i]%4==3){
          c[i]--;
          break;
        }
      }
    }
    else{
      if(h%2==1){
        swap(h,w);
      }
      x=0,y=h/2,z=(h/2)*(w/2);
    }
    int cnt=0;
    for(int i=0;i<26;i++){
      if(c[i]%4==2){
        cnt++;
        c[i]-=2;
        if(cnt==y){
          break;
        }
      }
    }
    for(int i=0;i<26;i++){
      if(c[i]%4!=0){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
}