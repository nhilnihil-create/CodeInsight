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
#include<complex>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int h, w;
    cin >> h >> w;
    int cnt[26] = {0};
    rep(i, h) rep(j, w) {
        char tmp_c;
        cin >> tmp_c;
        ++cnt[tmp_c-'a'];
    }
    if ( h == 1 && w == 1 ) {
        cout << "Yes" << endl;
        return 0;
    }
    vector<int> reqs;
    rep(i, (h+1)/2) rep(j, (w+1)/2) {
        int i_rev = h - 1 - i;
        int j_rev = w - 1 - j;
        int req = ( i == i_rev ? 1 : 2 ) * ( j == j_rev ? 1 : 2 );
        reqs.push_back(req);
    }
    sort(reqs.begin(), reqs.end());
    reverse(reqs.begin(), reqs.end());
    for ( auto tmp_req : reqs ) {
        bool flg = false;
        for ( int j = 0; j < 26; ++j ) {
            if ( tmp_req <= cnt[j] ) {
                cnt[j] -= tmp_req;
                flg = true;
                break;
            }
        }
        if ( !flg ) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
