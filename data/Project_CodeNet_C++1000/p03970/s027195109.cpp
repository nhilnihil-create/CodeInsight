#include<bits/stdc++.h>
#define INF 2147483647
#define SYOU(x) setprecision(x)
using namespace std;
long long i[10000][10000];
long long u[1111111];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,d=0,e=1,f=0;
  string s="CODEFESTIVAL2016",w;
  cin >>w;
  for(int n=0;n<16;n++){
    if(w[n]!=s[n]) d++;
  }
  cout <<d<<'\n';
  return (0);
}
