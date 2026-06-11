#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {

    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    rep(i,N) cin >> x[i];

    int ans = 0;
    rep(i,N){
        int distA = 2*x[i];
        int distB = 2*abs(x[i]-K);
        ans += min(distA,distB);
    }

    cout << ans <<endl;

    return 0;

}