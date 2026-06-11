#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N, x;
    cin >> N >> x;
    vector<int64_t> a(N);
    rep(i, 0, N) cin >> a.at(i);
    int64_t count = 0;
    rep(i, 0, N){
        if (a.at(i) > x){
            count += (a.at(i) - x);
            a.at(i) = x;
        }
    }
    rep(i, 0, N - 1){
        int64_t b = a.at(i + 1) + a.at(i);
        if (b > x){
            count += (b - x);
            a.at(i + 1) -= (b - x);
        }
    }
    cout << count << endl;
}