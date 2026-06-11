#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin>>n;
  string s,t;
  cin>>s;
  t=s;
  
  int a=0,b=0;
  rep(i,n){
    if(s[i]=='(') a++;
    else b++;
    if(b>a){
      t = '('+t;
      a = 0;
      b = 0;
    }
  }
  if(a>b) rep(i,a-b) t = t+')';
  cout << t;
}


