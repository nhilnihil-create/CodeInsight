#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
  ll n, v=0;
  cin >> n;
  vecll a(3 * n);
  forll(i, 0, 3 * n)
	cin >> a[i];
  sort(a.begin(), a.end());
  for (int i=n; i<3*n; i+=2)
	v += a[i];
  cout << v << endl;
}
