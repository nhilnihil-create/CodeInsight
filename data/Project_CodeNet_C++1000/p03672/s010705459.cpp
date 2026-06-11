#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int  main(){
  string s;cin>>s;
  int m=s.size()/2;
  rep(i,m){
    if(i==0){continue;}
    int n=m-i;
    string s1,s2;
    s1=s.substr(0,n);
    s2=s.substr(n,n);
    if(s1==s2){cout<<2*n;break;}
  }
}