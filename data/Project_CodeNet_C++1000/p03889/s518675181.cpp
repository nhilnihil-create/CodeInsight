#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;

main()
{
  string s;
  bool flag = true;
  cin >> s;
  
  Rep(i, s.size()/2) {
    if( s[i] == 'b' ) {
      if( s[s.size()-1-i] != 'd' ) flag = false;
    } else if( s[i] == 'd' ) {
      if( s[s.size()-1-i] != 'b' ) flag = false;
    } else if( s[i] == 'p' ) {
      if( s[s.size()-1-i] != 'q' ) flag = false;
    } else {
      if( s[s.size()-1-i] != 'p' ) flag = false;
    }
  }

  if( flag && !(s.size() % 2) ) cout << "Yes\n";
  else cout << "No\n";
  
}
