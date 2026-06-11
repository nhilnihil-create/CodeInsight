#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  ll x;
  cin >> x;
  int up;
  if(x%11==0) up = 0;
  else if(x%11<7) up= 1;
  else if(x%11>=7) up= 2;
  cout << (x/11)*2 + up << endl;
}