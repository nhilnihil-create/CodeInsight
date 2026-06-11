#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const int MOD = 1e9+7;
 
int main() {
	int A,B,C,D;
  	cin >> A >> B >> C>> D;
  	vi time(101);
  	for(int i = A; i<=B ;i++) time[i]++;
  	for(int i = C; i<=D ;i++) time[i]++;
  	int ans = 0;
  	rep(i,101){
    	if(time[i] == 2) ans++;
    }
  	if(ans != 0){
  		cout << ans-1 << endl;
    }
  	else cout << 0 << endl;
}