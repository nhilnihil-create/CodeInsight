#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  bool ok = false;
  int a, b, c, i = 0, ans = 0;
  cin >> a >> b >> c;
  do{
    i += a;
    if(i % b == c){
      //cout << i << endl; 
      ok = true;
      break;
    }
  }while(i <= 10000);

  if(ok)cout << "YES" << endl;
  else cout << "NO" << endl;;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}