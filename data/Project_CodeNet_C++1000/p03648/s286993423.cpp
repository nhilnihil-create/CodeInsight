#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define rep(i,x) for(int i=0;i<x;i++)

int main()
{
  ll K;
  ll a[50];

  cin >> K;

  ll t = (ll)(K/50);

  cout << 50 << endl;
  rep(i,50)
  {
    a[i] = i-K%50;
    if(a[i]<0)
      a[i]+=51;
    cout << a[i]+t << " ";
  }

  cout << endl;
  return 0;
}

