#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0, max_v = 0, a[100002] = {0}, n;
  cin >> n;
  REP(i,0,n){
    int inter;
    cin >> inter;
    a[inter]++;
    a[inter+1]++;
    a[inter+2]++;
    max_v = max(inter+2, 0);
  }
  REP(i,0,max_v+1){
    ans = max(ans, a[i]);
  }
  cout << ans << endl;
  
  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}