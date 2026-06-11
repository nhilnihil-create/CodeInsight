#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll n, m; cin >> n >> m;

    ll sum = 0;
    if(m-2*n>=0){
        sum += n;
        sum += (m-2*n)/4LL;
    }
    else{
        sum += m/2;
    }

    cout << sum << endl;
    return 0;
}
