#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string a, b, c;
  cin >> a >> b >> c;
  int x=(int)a.size(), y=(int)b.size(), z=(int)c.size(), p=0, q=0, r=0;
  char o='a';
  while(true){
    if(o=='a'){
      o=a[p];
      p++;
    }
    else if(o=='b'){
      o=b[q];
      q++;
    }
    else{
      o=c[r];
      r++;
    }
    if(x==p-1||y==q-1||z==r-1)break;
  }

  if(x==p-1)cout << "A\n";
  else if(y==q-1)cout << "B\n";
  else cout << "C\n";

  return 0;
}