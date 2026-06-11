
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
  ll x,y; cin >>x>>y;
  if(x==-y){
    cout <<1<<endl;
    return  0;
  }
  if(abs(x)>abs(y)){
    if(x*y>0){
      if(x>0){
        cout <<abs(x)-abs(y)+2<<endl;
      }else{
        cout <<abs(x)-abs(y)<<endl;
      }
    }else if(x*y<0){
        cout <<abs(x)-abs(y)+1<<endl;
    }else{
      if(x>0)cout<<x+1<<endl;
      else cout <<-x<<endl;
    }
  }else{
    if(x*y>0){
      if(x>0){
        cout <<abs(y)-abs(x)<<endl;
      }else{
        cout <<abs(y)-abs(x)+2<<endl;
      }
    }else if(x*y<0){
        cout <<abs(y)-abs(x)+1<<endl;
    }else{
      if(y>0)cout<<y<<endl;
      else cout <<1-y<<endl;
    }
  }
}
    