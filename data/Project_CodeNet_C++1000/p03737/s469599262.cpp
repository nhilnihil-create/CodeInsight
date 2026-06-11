#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    string a, b, c;
    cin >> a >> b >> c;

    char ans[3] = {a[0] + ('A' - 'a'), b[0] + ('A' - 'a'), c[0] + ('A' - 'a')};

    cout << ans[0] << ans[1] << ans[2] << endl;

    return 0;
}