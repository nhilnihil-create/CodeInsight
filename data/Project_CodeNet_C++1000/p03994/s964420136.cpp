#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)
int main(){
    string s;
    int k;
    cin >> s >> k;

    vector<ll> cost_to_a(s.length());

    rep(i, s.length()) {
        ll tmp_cost = 'z' + 1 - s[i];
        
        if ( s[i] == 'a') {
            cost_to_a[i] = 0;
        }
        else if ( tmp_cost > k ) {
            cost_to_a[i] = -1;
        }
        else {
            cost_to_a[i] = tmp_cost;
        }
    }

    ll rest_cost = k;

    rep(i, s.length()) {
        if ( cost_to_a[i] == 0 || cost_to_a[i] == -1 ) {
            continue;
        }
        else if ( cost_to_a[i] > rest_cost ) {
            continue;
        }
        else {
            s[i] = 'a';
            rest_cost -= cost_to_a[i];
        }
    }

    if ( rest_cost > 0 ) {
        s[s.length()-1] = s[s.length()-1] + rest_cost % 26;
    }
        
    if ( s[s.length()-1] > 'z' ) {
        s[s.length()-1] = (char)(s[s.length()-1] - ( 'z' - 'a' ));
    }

    cout << s << endl;

    return 0;
}
