#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct BIT{
    int n;
    vector<T> d;
    BIT(int n = 0):n(n), d(n+1){}
    void add(int i, T x = 1){
        for(i++; i <= n; i += i&-i){
            d[i] += x;
        }
    }
    T sum(int i){
        T x = 0;
        for(i++; i; i -= i&-i){
            x += d[i];
        }
        return x;
    }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	BIT<ll> bit(n+1);
	vector<ll> a(n);
	ll ans = 0;
	rep(i,n){
		cin >> a[i];
		bit.add(i, a[i]);
		ll sum = bit.sum(i);
		if(i%2 == 1){
			if(sum >= 0){
				ans += 1 + sum;
				bit.add(i, -(1 + sum));
			}
		}
		else{
			if(sum <= 0){
				ans += 1 - sum;
				bit.add(i, 1 - sum);
			}
		}
	}
	ll cmp = 0;
	BIT<ll> bit2(n+1);
	rep(i,n){
		bit2.add(i, a[i]);
		ll sum = bit2.sum(i);
		if(i%2 == 0){
			if(sum >= 0){
				cmp += 1 + sum;
				bit2.add(i, -(1 + sum));
			}
		}
		else{
			if(sum <= 0){
				cmp += 1 - sum;
				bit2.add(i, 1 - sum);
			}
		}
	}
	chmin(ans, cmp);
	cout << ans << endl;
	return 0;
}