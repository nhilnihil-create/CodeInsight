#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b,i) do { cout << "["; for (int (i) = (a);(i) < (b);++(i)) cout << ary[(i)] << ((b)-1 == (i) ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

struct BinaryIndexedTree {
private:
	int n;
	vector<int> bit;
public:
	BinaryIndexedTree(int n_) {
		n = n_+10;
		bit = vector<int>(n,0);
	}

	void add(int a,int w) {
		for (int x = a;x <= n;x += x&-x) bit[x] += w;
	}

	int sum(int a) {
		int ret = 0;
		for (int x = a;x > 0;x -= x&-x) ret += bit[x];
		return ret;
	}
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<P> a(n);
    BinaryIndexedTree bit(m);
    for (int i = 0;i < n;++i) cin >> a[i].first >> a[i].second;
    sort(a.begin(),a.end(),[](P& a,P& b){return a.second-a.first < b.second-b.first;});
    int r = 0;
    for (int i = 1;i <= m;++i) {
        while (r < n && a[r].second-a[r].first+1 < i) {
            bit.add(a[r].first,1);
            bit.add(a[r].second+1,-1);
            r++;
        }
        int ans = n-r;
        for (int j = i;j <= m;j += i) ans += bit.sum(j);
        cout << ans << endl;
    }
    return 0;
}