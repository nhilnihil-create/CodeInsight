#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  int x = 'a'-'A';
  string a,b,c;
  cin >> a  >> b >> c;
  printf("%c%c%c",a[0]-x,b[0]-x,c[0]-x);
}
