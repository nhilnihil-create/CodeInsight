#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n, m, c=1, x=1e9 + 7;
  cin >> n >> m;
  if(abs(n-m) > 1){
	cout << 0 << endl;
    return 0;
  }
  forll(i, 1, n+1)
	c = c * i % x;
  forll(i, 1, m + 1)
	c = c * i % x;
  if (n == m)
	cout << c * 2 % x << endl;
  else
	cout << c << endl;
}
