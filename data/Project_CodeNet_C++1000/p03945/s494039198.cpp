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
  string s;
  cin >> s;
  ll c=0;
  forll(i, 1, s.size()){
	if (s[i-1] != s[i])
	  c++;
  }
  cout << c << endl;
}

