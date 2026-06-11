#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int N, K;
    cin >> N >> K;
    K++;

    vector<int> a(N), b(N);
    rep(i, N)cin >> a[i] >> b[i];

    long long ans = 0;
    vector<int> use(N);
    iota(all(use), 0);
    
    for(int digit = 30; digit >= 0; digit--){
        int bit = (1 << digit);
        if(bit & K){
            long long sum = 0;
            rep(i, (int)use.size()){
                if(!(bit & a[use[i]]))sum += b[use[i]];
            }
            chmax<long long>(ans, sum);
        } else {
            vector<int> tmp;
            rep(i, (int)use.size()){
                if(!(bit & a[use[i]]))tmp.push_back(use[i]);
            }
            use = tmp;
        }
    }

    cout << ans << endl;
    return 0;

}