#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main() {
    int N, K;
    cin >> N >> K;
    ll ans = K*pow(K-1,N-1);
    cout << ans << endl;
}

