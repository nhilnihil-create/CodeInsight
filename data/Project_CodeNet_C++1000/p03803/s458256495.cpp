#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 1 ; i <=(n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
double pi=3.141592;
int main() {
  int a,b;
  cin>>a>>b;
  if(a==1||b==1){ 
    if(a==1&&b==1)  cout<<"Draw"<<endl;
    else if(a!=1)  cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
    
  }
  else {
    if(a<b)cout<<"Bob"<<endl;
    else if(b<a) cout<<"Alice"<<endl;
    else cout<<"Draw"<<endl;
  }
}