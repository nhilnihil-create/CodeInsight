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
  string s, t, tt;
  char c;
  ll count, minv=LLONG_MAX;
  vecll alpha(26, 0);
  cin >> s;
  forll(i, 0, s.size())
	alpha[s[i] - 'a']++;

  forll(i, 0, 26){
	if (alpha[i] == 0)
	  continue;
	c = i + 'a';
	t = s;
	tt = t;

	count = 0;
	while (t != string(t.size(), c)){
	  forll(j, 0, t.size() - 1){
		if(tt[j] == c || tt[j + 1] == c)
		  t[j] = c;
	  }
	  count++;
	  tt = t;
	  t.pop_back();
	  if(t == "")
		break;
	}
	minv = min(minv, count);
  }
  cout << minv << endl;
}
