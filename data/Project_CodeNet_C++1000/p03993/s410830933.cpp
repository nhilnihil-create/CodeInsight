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
  int n; cin>>n;
  vector<int> v(n);
  rep(i,n) cin >>v[i];
  int ans=0;
  rep(i,n){
    if(i+1==v[v[i]-1]) ans++;
  }
  cout<<ans/2<<endl;
}