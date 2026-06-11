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
  ll n, m, k;
  cin >> n >> m >> k;
  forll(i, 0, n + 1){
	forll(j, 0, m + 1){
	  if (i * m + j * n - 2 * i * j == k){
		cout << "Yes" << endl;
		return 0;
	  }
	}
  }
  cout << "No" << endl;
}
