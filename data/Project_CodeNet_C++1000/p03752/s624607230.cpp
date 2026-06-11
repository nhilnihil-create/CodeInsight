#include <bits/stdc++.h>
#include <set>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define reps(i, s, n) for (int i = s; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++) 
#define repsl(i, s, n) for (ll i = s; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl
#define readVarll(nam) ll nam; cin >> nam

ll d[20];
ll n, k;

ll calc1()
{
  ll ans = pow(10, 10) * n;
  rep(i, 1 << (n-1))
  {
    if(__builtin_popcount(i) != k-1)
    {
      continue;
    }

    ll befh = d[0];
    ll tmp = 0;
    reps(j, 1, n)
    {
      if(i & 1 << (j-1))
      {
        tmp += max(0LL, befh - d[j] + 1);
        befh = max(befh+1, d[j]);
      }
      else
      {
        befh = max(befh, d[j]);
      }
      
    }
    ans = min(ans, tmp);
  }

  return ans;
}

ll calc2()
{
  ll ans = 0;
  ll bef = d[0];
  reps(i, 1, n)
  {
    if(d[i] <= bef)
    {
      ans += bef - d[i] + 1;
      bef++;
    }
    else
    {
      bef = d[i];
    }
  }

  return ans;
}

int main()
{
  cin >> n >> k;
  
  repl(i, n)
  {
    cin >> d[i];
  }
  
  // srand((unsigned)time(NULL));
  // rep(i, 10)
  // {
  //   n = (rand() % 15) + 1;
  //   k = (rand() % n) + 1;
  //   rep(j, n)
  //   {
  //     d[j] = (rand() % 1000000000) + 1;
  //   }

  //   ll an1 = calc1();
  //   ll an2 = calc2();
  //   if(an1 != an2)
  //   {
  //     outdeb("wrong", an1, an2);
  //     outdeb("n,k=",n,k);
  //     rep(j, n)
  //     {
  //       cout << d[j] << " ";
  //     }
  //     cout << endl;
  //   }
  // }

  cout << calc1() << endl;
  //cout << calc2() << endl;
  return 0;
}