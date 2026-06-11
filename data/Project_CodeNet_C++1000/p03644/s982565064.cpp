#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  int N,cnt=1;

  cin >> N;

  while (N >= pow(2,cnt))
  {
    cnt++;
  }

  cout << pow(2,cnt-1) << endl;
  return 0;
}