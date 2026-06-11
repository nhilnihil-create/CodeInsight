#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000000;

#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep1(i,n) for(int i=1; i<=(int)(n); i++)
#define all(c) c.begin(),c.end()

int main() {
    string S;
    cin >> S ;

    ll ans = 0;
    int size = S.size();
    rep (i, 1 << (size-1)) {
        ll sum = 0;
        string tmp = "";
        tmp += S.at(0);
        rep (j, (size-1)) {
            if ((i >> j) & 1) {
                sum += stoll(tmp.empty() ? "0" : tmp);
                tmp = "";
                tmp += S.at(j+1);
            } else {
                tmp += S.at(j+1);
            }
        }
        sum += stoll(tmp);
        ans += sum;
    }
    cout << ans << endl;
}
