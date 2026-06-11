#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
vector <int> x(10000);
int main() {
    int N , M;
    cin >> N >> M;
    ll ans = 1;
    if(N == M + 1 || N + 1 == M){
        for(int i = N; i >= 1; i--){
            ans*=i;
            if(ans >= 1000000007){
                ans = ans % 1000000007;
            }
        }
        for(int i = M; i >= 1; i--){
            ans*=i;
            if(ans >= 1000000007){
                ans = ans % 1000000007;
            }
        }
        cout << ans << endl;
    }
    else if(N == M){
        for(int i = N; i >= 1; i--){
            ans*=i;
            if(ans >= 1000000007){
                ans = ans % 1000000007;
            }
        }
        for(int i = M; i >= 1; i--){
            ans*=i;
            if(ans >= 1000000007){
                ans = ans % 1000000007;
            }
        }
        cout << ans * 2 % 1000000007 << endl;
    }
    else{
        cout << 0 << endl;
    }
}