#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    vector<ll> sum(110000, 0);
    for (int i = 0; i < N; i++){
      ll tmp = 0;
      cin >> tmp;
      sum[tmp]++;
      sum[tmp + 1]++;
      sum[tmp + 2]++;
    }
    ll out = 0;
    for (int i = 0; i < 110000; i++){
      out = max(out, sum[i]);
    }
    cout << out << endl;
    return 0;
}