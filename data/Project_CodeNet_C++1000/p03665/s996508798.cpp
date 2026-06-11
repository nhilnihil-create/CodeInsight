#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll N,P;
    string S;
    cin >> N>>P;

    vector<ll> A(N);
    REP(i, N)
        cin >> A.at(i);

        ll dp[N + 1][2];

    /*REP(i,N){
        REP(j,2){
            dp[i][j] = 0;
        }
    }*/

    if(A.at(0)%2==0){
        dp[0][0]=2;
        dp[0][1] = 0;
    }
    else{
        dp[0][1]=1;
        dp[0][0] = 1;
    }

    REPS(i,N-1){
        if(A.at(i)%2==0){
            dp[i][0] = 2 * dp[i - 1][0];
            dp[i][1] = 2 * dp[i - 1][1];
        }
        else{
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
        }
    }

    cout << dp[N - 1][P] << endl;
}

