#include<bits/stdc++.h>
#define LL long long
#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=n-1;i>=0;--i)
#define REPA(i,n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define PII pair<int,int>
#define PLI pair<long long, int>
#define PLL pair<long long, long long>
#define MOD ((LL)1e9+7) 
#define INF ((LL)1e9+7)
#define INFLL ((LL)1e18)
#define ALL(x) (x).begin(),(x).end()
#define BIT(x) (1LL << (x))
using namespace std;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

LL modpow(LL x, LL b){
	LL res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

LL modinv(LL x){
	return modpow(x, MOD-2);
}

class union_find{
	public:
		int size;
		vector<int> parent;
		vector<int> union_size;
		union_find(int N){
			parent.resize(N);
			union_size.resize(N, 1);
			size = N;
			REP(i, N){
				parent[i] = i;
			}
		}

		int get_parent(int p){
			int d = parent[p];
			if(d == p)return p;
			return parent[p] = get_parent(d);
		}

		int get_union_size(int p){
			return union_size[get_parent(p)];
		}

		void merge(int a,int b){
			int ap = get_parent(a);
			int bp = get_parent(b);
			if(ap != bp){
				parent[bp] = ap;
				union_size[ap] += union_size[bp];
			}
		}

		int count(int lp = 0){
			vector<char> used(size, false);
			int res = 0;
			for(int i=lp;i<size;++i){
				if(!used[get_parent(parent[i])]){
					used[get_parent(parent[i])] = true;
					++res;
				}
			}
			return res;
		}

		bool is_brother(int a, int b){
			return get_parent(a) == get_parent(b);
		}
};


int main(){
	int N;
	int K, L;
	cin >> N;
	cin >> K >> L;
	union_find S(N), T(N);
	REP(i, K){
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		S.merge(a, b);
	}
	REP(i, L){
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		T.merge(a, b);
	}
	map<PII, int> m;
	REP(i, N){
		++m[PII(S.get_parent(i), T.get_parent(i))];
	}
	bool flag = false;
	REP(i, N){
		if(flag)cout << " ";
		flag = true;
		cout << m[PII(S.get_parent(i), T.get_parent(i))];
	}
	cout << endl;
}
