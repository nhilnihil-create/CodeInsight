#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;
  cout<<( (s.substr(0,4)=="YAKI")?"Yes" : "No" )<<endl;
  return 0;
}