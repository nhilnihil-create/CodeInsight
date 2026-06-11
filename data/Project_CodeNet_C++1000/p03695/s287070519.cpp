#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  int ans = 0;
  int n, a[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  cin >> n;
  REP(i,0,n){
    int inter;
    cin >> inter;
    //cout << inter << " : "; //--debug
    REP(j,1,9){
      //cout << j*400 << " "; //--debug
      if(inter < j*400){
        a[j-1]++;
        //cout <<"=>" << j; //--debug
        break;
      }
    }
    //cout  <<endl; //--debug
    if(inter >= 3200)a[8]++;
  }
  REP(i,0,8){
    if(a[i]>0){
      ans++;
    }
  }
  cout << max(ans,1) << " " << ans + a[8];

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}