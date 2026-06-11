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
  ll a, b, c, m=LLONG_MAX;
  cin >> a >> b >> c;
  if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
	cout << 0 << endl;
  else{
	m = min(m, a * b);
	m = min(m, b * c);
	m = min(m, c * a);
	cout << m << endl;
  }
}