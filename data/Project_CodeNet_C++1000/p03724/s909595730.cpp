#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<string>
#include<numeric>
using namespace std;
typedef long long ll;
//ll mod = 1e9+7;
ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> ab(m);
    rep(i, m) {
        int tmp_a, tmp_b;
        cin >> tmp_a >> tmp_b;
        --tmp_a, --tmp_b;
        ++ab[tmp_a], ++ab[tmp_b];
    }
    rep(i, m) {
        if ( ab[i] & 1 ) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
