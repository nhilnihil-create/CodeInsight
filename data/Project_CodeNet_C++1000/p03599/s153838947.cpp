#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


int INF = 1e9;
int NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
double EPS = 1e-9;
double PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------

//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c, d, e, f;
    cin >> a>> b >> c >> d >> e >> f;

    vll vec;

    for(ll i=0;c*i<=f;i++){
        for(ll j=0;j*d<=f;j++){
            ll tmp = c*i + d*j;
            if(tmp<=f){
                vec.PB(tmp);
            }
        }
    }
    sort(ALL(vec));


    double na = 0;
    ll nw = 0;
    ll ns = 0;

    for(ll i=0;i<30;i++){
        for(ll j=0;j<30;j++){
            ll wat = 100*a*i + 100*b*j;
            ll maxi = wat/100*e;
            ll lb, ub;
            lb = -1;
            ub = SZ(vec);
            while(ub-lb>1){
                ll mid = (ub+lb) / 2;
                if(vec[mid]+wat<=f && vec[mid]<=maxi){
                    lb = mid;
                }
                else{
                    ub = mid;
                }
            }
            if(lb==-1){
                continue;
            }
            lb = vec[lb];
            double tmpa = (double)(lb)/(double)(wat+lb);
            if(tmpa>=na){
                na = tmpa; 
                nw = wat;
                ns = lb;
            }
        }
    }

    cout << nw+ns <<" "<<ns <<endl;


    
    return 0;
}

