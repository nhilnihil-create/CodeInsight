# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)

struct INIT{
    INIT(){
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        cout << fixed << setprecision(13);
    }
}INIT;

struct BIT {
	vector<LL> bit;
	BIT(LL n) {
		bit.resize(n + 10);
	}

	//[0, i)
	LL sum(int i) {
		LL s = 0;
		for (int x = i - 1; x >= 0; x = (x&(x + 1)) - 1) {
			s += bit[x];
		}
		return s;
	}

    //[l, r)
    LL sum(int l, int r){
        return sum(r) - sum(l);
    }

    //[0, i]
    LL sum_open(int i) {
		LL s = 0;
		for (int x = i; x >= 0; x = (x&(x + 1)) - 1) {
			s += bit[x];
		}
		return s;
	}

    //[l, r]
    LL sum_open(int l, int r){
        return sum_open(r) - sum_open(l - 1);
    }
	void add(int a, LL w) {
		for (int x = a; x < (int)bit.size(); x |= x + 1) {
			bit[x] += w;
		}
	}

    //indexを返す
    int lower_bound(LL x){
        int l = -1, r = (int)bit.size();
        while(r - l > 1){
            int mid = (l + r)/2;
            if(sum_open(mid) < x){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;
    }

    //indexを返す
    int upper_bound(LL x){
        int l = -1, r = (int)bit.size();
        while(r - l > 1){
            int mid = (l + r)/2;
            if(sum_open(mid) <= x){
                l = mid;
            }else{
                r = mid;
            }
        }
        return r;
    }
};

LL n, k;
LL a[202020];
LL rui[202020];

int main(){
    cin >> n >> k;
    REP(i, n)cin >> a[i];
    REP(i, n)rui[i + 1] = rui[i] + a[i];
    vector<LL> v;
    for(int i = 0;i <= n;i++){
        v.emplace_back(rui[i] - k * i);
    }
    sort(ALL(v));
    UNIQUE(v);
    map<LL, int> zip;
    for(int i = 0;i <= n;i++)zip[v[i]] = i;
    LL ans = 0;
    BIT bit(202020);
    for(int i = 0;i <= n;i++){
        int pos = zip[rui[i] - k * i];
        ans += bit.sum(pos + 1);
        bit.add(pos, 1);
    }
    cout << ans << endl;
}