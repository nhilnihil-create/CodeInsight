#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl "\n"
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> figure;
    vector<ll> pat;
    string s;
    auto line2hash = [] (string s) -> ll {
        ll res = 0;
        for(char c: s) {
            if (c == '#') res = res*2+1;
            else res = res*2;
        }
        return res;
    };
    for(int i = 0; i < n; i++) {
        cin >> s;
        figure.push_back(line2hash(s));
    }
    for(int i = 0; i < m; i++) {
        cin >> s;
        pat.push_back(line2hash(s));
    }
    ll mask = (1LL << m) - 1;
    for(int k = 0; k < n-m+1; k++) {
        for(int i = 0; i <= n-m; i++) {
            vector<ll> tmp;
            for(int j = 0; j < m; j++) {
                tmp.push_back((figure[i+j] >> k) & mask);
            }
            // cout << tmp.size() << endl;
            if (tmp == pat) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    
    return 0;
}
