#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

int main()
{
  string s;
  while (cin >> s)
    {
      puts(((s.length()%2)^(s.front()==s.back()))?"First":"Second");
    }
}
