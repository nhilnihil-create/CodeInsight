#include <bits/stdc++.h>
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
using namespace std;

int main(){
  int a,b,c,d,ans=0;
  cin >> a >> b >> c >> d;
  
  vector<bool> x;
  x.resize(max(b,d));
  
  for(int i = a; i < b; i++) x[i] = true;
  for(int j = c; j < d; j++) if(x[j] == true) ans++;
  
  cout << ans << endl;
}