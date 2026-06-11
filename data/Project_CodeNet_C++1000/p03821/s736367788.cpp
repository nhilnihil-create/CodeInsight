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
  ll n, c=0, r, k;
  cin >> n;
  vecll a(n), b(n);
  forll(i, 0, n)
  	cin >> a[i] >> b[i];
  forll(i, 0, n){
	r = (a[n-1-i] + c) % b[n-1-i];
	if (r == 0)
	  continue;
	k = (a[n-1-i] + c) / b[n-1-i];
	c += (b[n-1-i] - r);
  }
  cout << c << endl;
}
