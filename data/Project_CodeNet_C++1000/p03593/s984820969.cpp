#include <bits/stdc++.h>
using namespace std;

//odd odd 
//odd even 
//even even 
int main(){
  int h,w; cin>>h>>w;
  vector<int> num(26,0);
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      char c; cin>>c;
      num[c-'a']++;
    }
  }
  int c1=0,c2=0,c4=0;
  for(int i=0;i<26;i++){
    if(num[i]%4==1){
      c1++; num[i]--;
    }
    if(num[i]%4==2){
      c2+=2; num[i]-=2;
    }
    if(num[i]%4==0) c4+=num[i];
  }
  if(h%2==1 && w%2==1){
    if(c1==1){
      if(h*w+1-h-w<=c4){
        c4-=h*w+1-h-w;
        c2+=c4;
        if(c2==h+w-2){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
    cout<<"No"<<endl;
    return 0;
  }else if(h%2==1){
    if(h*w-w<=c4){
      c4-=h*w-w;
      c2+=c4;
      if(c2==w){
        cout<<"Yes"<<endl;
        return 0;
      }
    }cout<<"No"<<endl;
    return 0;
  }else if(w%2==1){
    if(h*w-h<=c4){
      c4-=h*w-h;
      c2+=c4;
      if(c2==h){
        cout<<"Yes"<<endl;
        return 0;
      }
    }cout<<"No"<<endl;
    return 0;
  }else{
    if(c4==h*w){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}