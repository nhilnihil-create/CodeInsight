#include<bits/stdc++.h>
using namespace std;
using lli = long long;
lli n;

int main(void){
  cin >> n;
  lli p = 1;
  for(lli i = 1; i*i <= n; i++){
    if(n%i == 0) p = i;
  }
  lli q = n/p;
  string sp = to_string(p);
  string sq = to_string(q);
  cout << max(sp.size(), sq.size()) << endl;
  return 0;
}
