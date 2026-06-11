#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  int tmp=0;
  int world=1;
  vector<bool> yn(n,0);
  rep(i,n){
    if(s[i]=='a'){
      yn[i]=1;
      tmp++;
    }else if(s[i]=='b' && world<=b){
      yn[i]=1;
      tmp++;
      world++;
    }
    if(tmp==(a+b)){
      break;
    }
  }
  rep(i,n){
    if(yn[i]){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
}