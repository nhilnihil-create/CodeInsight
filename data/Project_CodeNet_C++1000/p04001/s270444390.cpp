#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 2147483647;

int main(){
    string S;    
    int N;
    cin >> S;
    N = S.size();
    ll ans = 0;
    rep(i, 0, 1<<N){
        ll st = 0;
        rep(j, 0, N){
            if ((i>>j)&1){
                st = st*10 + (S[j] - '0');
            }
            else{
                ans += st;
                st = 0;
            }
        }
        ans += st;
    }
    cout << ans << endl;
}