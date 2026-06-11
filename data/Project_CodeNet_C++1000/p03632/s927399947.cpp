#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  if(a<=c && b<=d){
    if(b-c>0) cout << b-c << endl;
    else cout << 0 << endl;
  }else if(a<=c && d<=b){
    if(d-c>0) cout << d-c << endl;
    else cout << 0 << endl;
  }else if(c<=a && b<=d){
    if(b-a>0) cout << b-a << endl;
    else cout << 0 << endl;
  }else{
    if(d-a>0) cout << d-a << endl;
    else cout << 0 << endl;
  }
}