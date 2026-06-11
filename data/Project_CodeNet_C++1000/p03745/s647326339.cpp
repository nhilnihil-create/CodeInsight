#include <bits/stdc++.h>
#define vsort(v) sort(v.begin(), v.end())
#define rvsort(v) sort(v.begin(), v.end(), greater<ll>())
#define vfind(v, target) find(v.begin(), v.end(), target)
#define notFound(v, target) (vfind(v, target) == v.end())
#define maxIndex(v) max_element(v.begin(), v.end()) - v.begin()
#define maxElement(v) *max_element(v.begin(), v.end())
#define minIndex(v) min_element(v.begin(), v.end()) - v.begin()
#define minElement(v) *min_element(v.begin(), v.end())
#define ll long long
#define rep(i, s, g) for (ll i = (s); i < (g); i++)
#define MOD 1000000007
using namespace std;

int main()
{
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i, 0, N) cin >> A[i];
  int updown = 0;
  ll ans = 1;
  rep(i, 0, N - 1) {
  	if (updown == 0 && A[i] < A[i + 1]) {
    	updown = 1;
    } else if (updown == 0 && A[i] > A[i + 1]) {
    	updown = -1;
    } else if (updown == -1 && A[i] < A[i + 1]) {
    	ans++;
      	updown = 0;
    } else if (updown == 1 && A[i] > A[i + 1]) {
    	ans++;
      	updown = 0;
    }
  }
  cout << ans << endl;
}