#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(a==1) a=14;
  if(b==1) b=14;

  if(a>b) puts("Alice");
  else if(a<b) puts("Bob");
  else if(a==b) puts("Draw");
}