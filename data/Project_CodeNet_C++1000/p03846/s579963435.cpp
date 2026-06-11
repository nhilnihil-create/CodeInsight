#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b)
{
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define all(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define F first
//#define S second

typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1000000;
const int minf = -1000000;
const ll lnf = 1e12;
const ll mlnf = -1e12;
const double e = 1e-10;

void debug_vector(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


//////////////////////
//// coding start ////
//////////////////////

// global variety

// function
void solve();

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}

void solve(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> cnt(N, 0);
    rep(i, N){
        cnt[A[i]]++;
    }
    long long ans = 0;  // ans = 2 ** m   flag = true;
    int m = N / 2;
    bool flag = true;
    if (N % 2 == 0){
        rep(i, N){
            if (i % 2 == 0){
                if (cnt[i] != 0){
                    flag = false;
                    break;
                }
            }
            else{
                if (cnt[i] != 2){
                    flag = false;
                    break;
                }
            }
        }
    }
    else{
        rep(i, N){
            if (i == 0){
                if (cnt[i] != 1){
                    flag = false;
                    break;
                }
            }
            else if (i % 2 == 1){
                if (cnt[i] != 0){
                    flag = false;
                    break;
                }
            }
            else{
                if (cnt[i] != 2){
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag){
        ans = 1;
        for (int i = 1; i <= m; i++){
            ans *= 2;
            ans %= MOD;
        }
    }
    printf("%lld\n", ans);

                       
}

