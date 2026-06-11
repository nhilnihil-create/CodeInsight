#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n = 3;
  vector<int> a(n); rep(i,n) cin >> a[i];
  int n5=0,n7=0;
  rep(i,n){    
    if(a[i] == 5) n5++;
    else if(a[i] == 7) n7++;
  }
  if(n5==2 && n7 == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
      
  
  return 0;
}
