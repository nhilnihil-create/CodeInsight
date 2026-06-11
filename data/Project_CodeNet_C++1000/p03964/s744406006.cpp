#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpl;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;
#define INF (int)(1e9)
#define MAXX 1.1529215e+18
#define inf 999999
#define EPS (1e-7)
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,n) for(int i=1;i<=(int)(n);i++)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define ALL(a)  a.begin(),a.end()
#define RALL(a) a.begin(),a.end(),greater<int>()
#define ROT(a) a.begin(),a.begin()+1,a.end()
#define RROT(a) a.begin(),a.end()-1,a.end()
#define PB push_back
#define MP make_pair
#define PI acos(-1.0)
#define sz(a) a.size()
const ll MOD = 1e9+7;
const int MAX = 10000000;
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }
//cout << 'H' << endl;
/*--------------------------------------------*/

int main(){
    //cout << fixed << setprecision(10)
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    ll a,b;
    cin >> a >> b;

    rep(i,N-1){
        ll tmp_a,tmp_b;
        cin >> tmp_a >> tmp_b;

        ll ia = tmp_a, ib = tmp_b;

        ll tm = max((a+tmp_a-1) / tmp_a,(b+tmp_b-1) / tmp_b);

        if(tm > 1.0){
            tmp_a *=tm;
            tmp_b *=tm;
            a = tmp_a;
            b = tmp_b;
        }
        

        // while(tmp_a < a || tmp_b < b){
        //     tmp_a = ia * j;
        //     tmp_b = ib * j;
        //     j++;
        // }

        chmax(a,tmp_a);
        chmax(b,tmp_b);


        

        // if(tm < 1.0){
        //     if(tmp_b / double(b) < 1.0){
        //         ll t = (b+tmp_b-1) / tmp_b;
        //         tmp_a *= t;
        //         tmp_b *= t;
        //     }else{
        //         ll t = (a+tmp_a-1) / tmp_a;                
        //         tmp_a *= t;
        //         tmp_b *= t;
        //     }
        // }else{

        // }
        //     a = tmp_a;
        //     b = tmp_b;
        
       // cout << tmp_a << ' ' << tmp_b << endl;


    }

    cout << a + b << endl;

}