#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

class FenwickTree {
private:
    int bit_size;
    vector<LL> bit;

public:
    FenwickTree(int siz): bit_size(siz), bit(siz + 1) {}

    void add(int num, LL val) {
        for(int i = num + 1; i <= bit_size; i += i & -i) {
            bit[i] += val;
        }
    }

    LL sum(int end){
        LL res = 0;
        for(int i = end + 1; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

    void init(LL val) {
        for(int i = 1; i <= bit_size; i++) {
            add(i, val);
        }
    }

    int lower_bound(LL val) {
        if(val <= 0) return 0;
        int i = 0, n = 1;
        while(n * 2 <= bit_size) n *= 2;
        for(int k = n; k > 0; k /= 2) {
            if(i + k <= bit_size && bit[i + k] < val) {
                val -= bit[i + k];
                i += k;
            }
        }
        return i + 1;
    }
};

int main(){
	LL N, K;
	cin >> N >> K;
	vector<LL> a(N);
	rep(i,N) cin >> a[i];
	vector<LL> s(N+1), b(N+1);
	rep(i,N) s[i+1]=s[i]+a[i];
	rep(i,N) b[i+1]=s[i+1]-K*(i+1);
	vector<LL> vals(N+1);
	vector<int> c(N+1);
	rep(i,N+1) vals[i]=b[i];
	sort(vals.begin(),vals.end());
	vals.erase(unique(vals.begin(),vals.end()),vals.end());
	rep(i,N+1){
		int id=lower_bound(vals.begin(),vals.end(),b[i])-vals.begin();
		c[i]=id;
	}
	LL ans=0;
	FenwickTree FT(N+1);
	rep(i,N){
		FT.add(c[i],1);
		ans+=FT.sum(c[i+1]);
	}
	cout << ans << endl;

	return 0;
}