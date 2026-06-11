#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct BIT{
    private:
        vector<T> array;
        const int n;
    public:
        BIT(int _n) : array(_n + 1, 0), n(_n) {}
        // [1, i], i is 1-indexed
        T sum(int i){
            T s = 0;
            while(i > 0){
                s += array[i];
                i -= i & -i;
            }
            return s;
        }
        // [i, j), i and j are 1-indexed
        T sum(int i, int j){
            T ret_i = sum(i-1);
            T ret_j = sum(j);
            return ret_j - ret_i;
        }
        // i is 1-indexed
        void add(int i, T x){
            while(i <= n){
                array[i] += x;
                i += i & -i;
            }
        }

        // debug
        void print(){
            for(int i = 1; i < (int)array.size(); ++i){
                cout << sum(i, i+1) << " ";
            }
            cout << endl;
        }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> sum(n+1, 0);
	rep(i,n){
		ll a;
		cin >> a;
		sum[i+1] = sum[i] + a - k;
	}
	vector<ll> cmp = sum;
	sort(cmp.begin(), cmp.end());
	cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
	BIT<ll> bit(n+5);
	ll ans = 0;
	rep(i,n+1){
		int idx = lower_bound(cmp.begin(), cmp.end(), sum[i]) - cmp.begin();
		ans += bit.sum(idx+1);
		bit.add(idx+1, 1);
	}
	cout << ans << endl;
	return 0;
}
