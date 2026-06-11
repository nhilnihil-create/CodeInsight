#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,res=0,cr=0;
  string S;

  cin >> N;
  cin >> S;

  REPI(S.size())
  {
    if (S[i] == 'I')
      cr++;
    else
      cr--;
    
    res = max(res,cr);    
  }

  cout << res << endl;
  return 0;
}