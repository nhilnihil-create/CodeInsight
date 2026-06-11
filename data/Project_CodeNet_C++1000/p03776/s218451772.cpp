#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> l_l;
typedef pair<int , int> i_i;
typedef vector<ll> vel;
typedef vector<int> vei;
typedef vector<char> vec;
typedef vector<bool> veb;
typedef vector<string> ves;
typedef vector<vector<ll>> ve_vel;
typedef vector<vector<int>> ve_vei;
typedef vector<vector<char>> ve_vec;
typedef vector<vector<bool>> ve_veb;
typedef vector<vector<string>> ve_ves;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define rep2(i,n) for(int i=2;i<(int)(n);i++)
#define repk(i,k,n) for(int i=k;i<(int)(n);i++)
#define fs first
#define sc second
#define pub push_back
#define pob pop_back
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define maxel(a) *max_element(all(a))
#define minel(a) *min_element(all(a))
#define acc accumulate
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define mod (1000000007)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N, A, B; cin >> N >> A >> B;
    vel v(N); rep(i,N) cin >> v[i];
    sort(rall(v));
    ll comb[51][51];
    for(int i = 0; i <= 50; i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for(int i = 1; i <= 50; i++){
        for(int j = 1; j <= i - 1; j++){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }

    ll sum = 0LL;
    rep(i,A) sum += v[i];
    ld av = (ld) sum / A;
    cout << fixed << setprecision(20) << av << endl;
    ll key = v[A-1]; int cnt = 0; int choice = 0;
    rep(i,N) if(v[i] == key) cnt++;
    rep(i,A) if(v[i] == key) choice++;
    ll ans = 0LL;
    if(v[0] != v[A-1]) cout << comb[cnt][choice] << endl;
    else {
        for(int i = A; i <= B;i++) {
            ans += comb[cnt][i];
        }
        cout << ans << endl;
    }
    return 0;
}
