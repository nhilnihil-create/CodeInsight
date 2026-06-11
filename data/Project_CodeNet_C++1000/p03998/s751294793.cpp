#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  string a,b,c;
  cin >> a >>b >> c;
  int ag=-1,bg=-1,cg=-1;
  char q='a';
  while(1){
    if(q=='a'){
      ag++;
      if(ag==a.size()){cout << 'A' << endl; return 0;}
      q=a[ag];
      continue;
    }
    if(q=='b'){
      bg++;
      if(bg==b.size()){cout << 'B' << endl; return 0;}
      q=b[bg];
      continue;
    }
    if(q=='c'){
      cg++;
      if(cg==c.size()){cout << 'C' << endl; return 0;}
      q=c[cg];
      continue;
    }

  }
}