#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
#define int ll


int m,n;
int a[100010];



struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
 
public:
    LazySegmentTree(const vector<ll>& v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
 
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
 
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }
 
    void add_inter(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add_inter(a, b, x, 2*k+1, l, (l+r)/2);
            add_inter(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }
 
    ll get_inter(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = get_inter(a, b, 2*k+1, l, (l+r)/2);
        ll vr = get_inter(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};

signed main()
{
	cin >> n >> m;

	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
		a[i]--;
	}

	int sum = 0;

	LazySegmentTree seg(vector<ll>(3 * m,0LL));

	for(int i = 1;i < n;i++)
	{
		int from = a[i - 1];
		int to = a[i];
		if(from > to) to += m;
		//from < to
			

		int dist = (to - from)% m;

		sum += dist;
		
		to = a[i] + 1;
		from =  a[i] - (dist - 1) + 1;
		
		if(from >= 0)
		{
			seg.add_inter(from , to,1);
			seg.add_inter(to,to + 1,-(dist - 1));
			from += m;
			to += m;


			seg.add_inter(from , to,1);
			seg.add_inter(to,to + 1,-(dist - 1));
		}
		else
		{
			from += m;
			to += m;
			seg.add_inter(from , to,1);
			seg.add_inter(to,to + 1,-(dist - 1));
			from += m;
			to += m;


			seg.add_inter(from , to,1);
			seg.add_inter(to,to + 1,-(dist - 1));
		}


	}

	ll minus = 0;

	for(int i = 0;i < 3 * m;i++)
	{
		//cout << seg.get_inter(0,i + 1) << endl;
		minus = max(minus , seg.get_inter(0,i + 1));
	}

	//cout << sum << " " << minus << endl;
	cout << sum - minus << endl;
}

