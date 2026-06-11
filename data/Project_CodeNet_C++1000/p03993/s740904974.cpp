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
  ll n, c=0;
  cin >> n;
  vecll a(n);
  forll(i, 0, n)
	cin >> a[i];
  forll(i, 0, n){
	if(a[a[i]-1] == i+1)
	  c++;
  }
  cout << c/2 << endl;
}