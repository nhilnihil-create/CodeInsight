#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n,pre; cin >>n >>pre;
  int cnt = 1, jud = 0;
  int a;
  while(cin >>a){
    if(jud==1 && a<pre) cnt++, jud=0;
    else if(jud==2 && a>pre) cnt++, jud=0;
    else if(jud==0 && a>pre) jud=1;
    else if(jud==0 && a<pre) jud=2;
    pre = a;
  }
  cout << cnt << endl;
  return 0; 
}