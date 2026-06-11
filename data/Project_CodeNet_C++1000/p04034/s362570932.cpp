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
  ll n, m, x, y, c=0;
  cin >> n >> m;
  vecll a(n, 0);
  vecll b(n, 1);
  a[0] = 1;
  forll(i, 0, m){
	cin >> x >> y;
	b[x-1]--;
	b[y-1]++;
	if(a[x-1] == 1){
	  a[y-1] = 1;
	  if (b[x-1] == 0)
		a[x-1] = 0;
	}
  }
  forll(i, 0, n){
	if (a[i] == 1)
	  c++;
  }
  cout << c << endl;
}
