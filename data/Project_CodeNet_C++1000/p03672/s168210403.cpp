#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  ll ans = 0;
  string s;
  cin >> s;
  ll n = s.length();
  if(n % 2 == 0)n -= 1;
  for(int i=n-1 ; i>=2 ; i-=2){
    int j = i/2;
    string s2 = s.substr(0,i);
    string h1 = s2.substr(0,j);
    string h2 = s2.substr(j,i);
    //cout << s2 << " : " << j << "/ "<< h1 << " : " << h2 << endl;
    if(h1 == h2){
      ans=i;
      break;
    }
  }
  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}