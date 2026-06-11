#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int main()
{
  string str; cin>>str;
  bool n=false,w=false,s=false,e=false;
  for (auto c:str) {
    if (c=='N') n=true;
    if (c=='W') w=true;
    if (c=='S') s=true;
    if (c=='E') e=true;
  }
  if (!(n^s) && !(e^w)) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
