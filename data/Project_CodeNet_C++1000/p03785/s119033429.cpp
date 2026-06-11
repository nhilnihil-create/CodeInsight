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
  ll n, c, k, b=1, tc=0, tk;
  cin >> n >> c >> k;
  vecll t(n);
  forll(i, 0, n)
	cin >> t[i];
  sort(t.begin(), t.end());
  tk = t[0];
  forll(i, 0, n){
	if (tc == c || t[i] - tk > k){
	  b++;
	  tc = 1;
	  tk = t[i];
	  continue;
	}
	tc++;
  }
  cout << b << endl;
}

