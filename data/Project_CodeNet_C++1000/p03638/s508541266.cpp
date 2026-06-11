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
  ll H, W, N; cin >> H >> W >> N;
  vector<vector<ll>> mtrx(H, vector<ll>(W));
  vector<ll> colors(N);
  rep(i, 0, N) cin >> colors[i];
  ll k = 0;
  rep(i, 0, H) {
  	if (i % 2 == 0) {
    	for (ll j = 0; j < W; j++) {
        	mtrx[i][j] = k + 1;
         	colors[k]--;
          	if (colors[k] == 0) k++;
        }
    } else {
	    for (ll j = W - 1; j >= 0; j--) {
        	mtrx[i][j] = k + 1;
         	colors[k]--;
          	if (colors[k] == 0) k++;
        }
    }
  }
  rep(i, 0, H) {
  	rep(j, 0, W) {
    	cout << mtrx[i][j] << " ";
    }
    cout << endl;
  }
}