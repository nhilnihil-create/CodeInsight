#define _GLIBCXX_DEBUG
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
  ll n; cin >>n;
  vector<ll> a(n);
  rep(i,n) cin >>a[i];
  ll count=1;
  int k=0;
  rep2(i,0,n-1){
    if(a[i+1]-a[i]>0){
      if(k==-1){
        count++;
        k=0;
      }else{
        k=1;
      }
    }
    if(a[i+1]-a[i]<0){
      if(k==1){
        count++;
        k=0;
      }else{
        k=-1;
      }
    }
       
  }
  cout <<count<<endl;
} 