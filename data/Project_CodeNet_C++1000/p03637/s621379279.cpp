#include <bits/stdc++.h>  
using namespace std;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using graph =vector<vector<int>>;
using ll = long long int;

int  main(){
  int n;cin>>n;
  int odd=0,even=0,four=0;
  vector<ll> v(n);
  rep(i,n){
    cin>>v[i];
    if(v[i]%2==1)odd++;
    else if(v[i]%4==0)four++;
    else{even++;}
  }
  if(odd<=four){cout<<"Yes";}
  else if(even==0&&odd<=four+1){cout<<"Yes";}
  else{cout<<"No";}
}