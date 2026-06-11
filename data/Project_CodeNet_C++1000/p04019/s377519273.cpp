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
  string s;
  cin >> s;
  ll u=0, d=0, l=0, r=0;
  bool ok;
  forll(i, 0, s.size()){
	if (s[i] == 'N')
	  u += 1;
	else if (s[i] == 'W')
	  l += 1;
	else if (s[i] == 'S')
	  d += 1;
	else
	  r += 1;
  }
  if ((u > 0 && d > 0) || (u == d))
	if ((l > 0 && r > 0) || (l == r))
	  ok = true;
	else
	  ok = false;
  else
	ok = false;
  if (ok == true)
	cout << "Yes" << endl;
  else
	cout << "No" << endl;
}
