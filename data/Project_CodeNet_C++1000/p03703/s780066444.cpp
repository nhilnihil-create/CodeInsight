#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

template<typename T>
class BIT {
public:
    int N;
    vector<T> dat;

    BIT(int N) : N(N + 1) {
        dat.resize(N + 1, 0);
    }

    // sum[a0 + ... +ak)
    T get_sum(int k) {
        T ret = 0;
        //k & -kはkの２進表示の最も右のビットの表す数
        for(; k > 0; k -= (k & -k)) {
            ret += dat[k];
        }

        return ret;
    }

    //a[k] = a[k] + x;
    void add(int k, T x){
        k++;
        for(; k < N; k += (k & -k)) {
            dat[k] += x;
        }
    }
};

int compress(ll *x, int N){
  vector<ll> y;
  for(int i = 0; i < N; i++){
    y.push_back(x[i]);
  }

  sort(y.begin(), y.end());
  y.erase(unique(y.begin(), y.end()), y.end());

  for(int i = 0; i < N; i++){
    x[i] = lower_bound(y.begin(), y.end(), x[i]) - y.begin();
  }

  return (int)y.size();
}

//-------------------------------------------------------------------

int main(){
    int N;
    ll K;
    cin >> N >> K;
    ll a[N];
    ll sum[N + 1];
    sum[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    ll b[N + 1];
    for(int i = 0; i <= N; i++){
        b[i] = sum[i] - i * K;
    }

    compress(b, N + 1);

    ll ans = 0;
    BIT<int> bit = BIT<int>(N + 5);
    for(int i = 0; i <= N; i++){
        ans += bit.get_sum(b[i] + 1);
        bit.add(b[i], 1);
        //cout << i << endl;
    }

    cout << ans << endl;
    return 0;

}