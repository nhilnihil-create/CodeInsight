#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    ll x, t; cin >> x >> t;
    if(x<t){
        cout << 0 << endl;
    }
    else{
        cout << x-t << endl;
    }
    return 0;
}
