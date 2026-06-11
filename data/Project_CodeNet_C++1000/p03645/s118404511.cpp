#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }
 
int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> ab(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        ab[a-1].push_back(b-1);
    }
    for(auto aaa: ab[0]){
        for(auto bbb: ab[aaa]){
            if(bbb==N-1){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}