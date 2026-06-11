#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 0x3f3f3f3f; constexpr ll LLINF = 0x3f3f3f3f3f3f3f3f;
#define db(x) { cerr << #x << " = " << x << endl; }
template<class RIt> void dbarr(RIt frs, RIt lst){ cerr << "arr: "; for(int i = 0; i < (int)(lst-frs); i++) cerr << frs[i] << " \n"[i==(int)(lst-frs)-1]; }
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define fs first
#define sn second

int main() {
	cin.tie(0)->sync_with_stdio(0);
    set<char> ss;
    string s; cin >> s;
    for(char c : s) ss.insert(c);
    for(char i = 'a'; i <= 'z'; i++){
        if(ss.find(i) == ss.end()){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "None\n";
}

