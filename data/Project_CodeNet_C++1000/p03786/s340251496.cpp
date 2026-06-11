#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())

using namespace std;

int main()
{
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];
  vsort(A);
  ll color = 1, sum = A[0];
  rep(i, 0, N - 1) {
  	if (sum * 2 >= A[i + 1]) color++;
    else color = 1;
    sum += A[i + 1];
  }
  cout << color << endl;
}