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

int n, m;
int x[101010];
vector<int> Group[101010];

int main(){
    cin >> n >> m;
    REP(i, n)cin >> x[i];
    REP(i, n)Group[x[i] % m].emplace_back(x[i]);
    int ans = 0;
    vector<int> v;
    v.emplace_back(0);
    if(m % 2 == 0)v.emplace_back(m/2);
    for(auto i : v){
        ans += (int)Group[i].size() / 2;
    }
    for(int i = 1;i <= (m - 1)/2;i++){
        vector<int> s = Group[i], t = Group[m - i];
        if((int)s.size() < (int)t.size())swap(s, t);
        ans += (int)t.size();
        sort(ALL(s));
        int idx = 0;
        int cnt = (int)s.size() - (int)t.size();
        while(idx < (int)s.size() - 1 && cnt >= 2){
            if(s[idx] == s[idx + 1]){
                idx += 2;
                cnt -= 2;
                ans++;
                continue;
            }
            idx++;
        }
    }
    cout << ans << endl;
}