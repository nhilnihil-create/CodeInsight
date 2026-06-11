
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
/*
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
#define  P = pair<int, int>;
*/


int main(){

  string s;
  cin>>s;

  if(s.length() == 1){
    cout<<s[0]<<endl;
     return 0; }

  if(s.length() > 1){
  cout<<s[0];
  }

  for(int i=1;i<s.length();i++){
     if(i%2 == 0)
    cout<<s[i];
  }

return 0;
}