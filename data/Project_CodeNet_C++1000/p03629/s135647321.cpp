#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int N = 2e5+2;
const int A = 26;
char s[N];
int occur[A];
int d[N];
int choice[N];
int nxt[N];
int cal(int choice)
{
  return d[occur[choice]+1] + 1;
}
int main()
{
  while (~scanf("%s", s))
    {
      int len = strlen(s);
      fill(occur, occur+A, len);
      d[len] = 1;
      d[len+1] = 0;
      for (int i = len-1; i >= 0; --i)
	{
	  occur[s[i]-'a'] = i;
	  d[i] = cal(choice[i] = 0);
	  for (int c = 1; c < A; ++c)
	    {
	      int tmp = cal(c);
	      if (tmp < d[i])
		{
		  d[i] = tmp;
		  choice[i] = c;
		}
	    }
	  nxt[i] = occur[choice[i]]+1;	  
	}
      int cur = 0;
      while (cur < len)
	{
	  putchar(choice[cur]+'a');
	  cur = nxt[cur];
	}
      putchar('\n');
    }
}
