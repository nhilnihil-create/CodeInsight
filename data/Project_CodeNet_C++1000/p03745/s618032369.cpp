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
  ll n, c=1, a, pa=-1;
  char s='=';
  cin >> n;
  forll(i, 0, n){
	cin >> a;
	if (s == '='){
	  if (pa == -1){
		pa = a;
		continue;
	  }
	  if (a - pa > 0)
		s = '+';
	  else if (a-pa < 0)
		s = '-';
	  pa = a;
	}else{
	  if ((a - pa >= 0 && s == '+') || (a-pa <= 0 && s == '-'))
		pa = a;
	  else{
		s = '=';
		c++;
		pa = a;
	  }
	}
  }
  cout << c << endl;
}

