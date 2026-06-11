#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;

int main (){
    int N;
    cin >> N;
    vector<ll> a(3*N);

    rep(i,0,3*N) {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    ll ans = 0;

    rep(i,0,N) {
        ans += a[2*i+1];
    }
    cout << ans << endl;
}


