#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int a,b; cin >> a >> b;

  if(a%3==0 || b%3==0 || (a+b)%3==0){
    cout << "Possible" << endl;
    return 0;
  }

  cout << "Impossible" << endl;
  
  return 0;
}
