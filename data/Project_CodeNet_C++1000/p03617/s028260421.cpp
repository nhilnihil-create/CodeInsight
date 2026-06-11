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
  ll q, h, s, d, n, v;
  cin >> q >> h >> s >> d >> n;
  if (n % 2 == 0){
	v = n / 2 * d;
	v = min(v, n * s);
	v = min(v, n * 2 * h);
	v = min(v, n * 4 * q);
  }else{
	v = n * 4 * q;
	v = min(v, n * 2 * h);
	v = min(v, n * s);
	v = min(v, (n-1)/2 * d + s);
	v = min(v, (n-1)/2 * d + 2 * h);
	v = min(v, (n-1)/2 * d + 4 * q);
  }
  cout << v << endl;
}