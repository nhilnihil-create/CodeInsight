#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll mod= 1e9 + 7;



int main(){
  string s;
  cin >> s;
  string a="dreamer",b="eraser";
  int g=s.size();
  int d=0;
  bool ans=1;
  while(d<g){
    if(s[d]=='e'){
      for(int i=d;i<d+5;i++){
        if(s[i]!=b[i-d])ans=0;
      }
      d+=5;
      if(s[d]=='r')d++;
    }else 
    if(s[d]=='d'){
      for(int i=d;i<d+5;i++){
        if(s[i]!=a[i-d])ans=0;
      }
      d+=5;
      if(s[d]=='e' && s[d+1]=='r' && s[d+2]!='a')d+=2;
    }else{ans=0;}

    if(ans==0)break;
  }

  if(ans){cout << "YES" << endl;}else{cout << "NO" << endl;}
}