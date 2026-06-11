#include<iostream>
using namespace std;
typedef long long ll;
int main(){
  ll h,w,tc=0,fc=0;
  ll g0,g1;
  cin >> h >> w;
  if(w%2==1){
    swap(h,w);
  }
  g0 = g1 = 0;
  if(h%2==1){
    g1 = w/2;
  }
  if(w%2==1){
    g0 = 1;
    g1 = h/2 + w/2;
  }
  int clist[26]={};
  char c;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> c;
      clist[c-'a']++;
    }
  }
  for(int i=0;i<26;i++){
    if(clist[i]%4==1) fc++;
    else if(clist[i]%4==2) tc++;
    else if(clist[i]%4==3){
      fc++;
      tc++;
    }
  }
  if(g0>=fc&&g1>=tc){
    cout <<"Yes\n";
  }else{
    cout <<"No\n";
  }
}
