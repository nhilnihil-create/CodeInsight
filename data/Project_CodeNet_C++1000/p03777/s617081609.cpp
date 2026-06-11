#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  char a,b; cin >> a >> b;

  if(a=='H' && b == 'H') cout << "H" << endl;
  if(a=='H' && b == 'D') cout << "D" << endl;
  if(a=='D' && b == 'H') cout << "D" << endl;
  if(a=='D' && b == 'D') cout << "H" << endl;
  
  return 0;
}
