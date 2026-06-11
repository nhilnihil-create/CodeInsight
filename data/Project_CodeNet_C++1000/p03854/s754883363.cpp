#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, ll> pcl;

#define m0(x) memset(x, 0, sizeof(x))
#define all(x) x.begin(), x.end()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define asort(x) sort(all(x));
#define dsort(x, t) sort(x.begin(), x.end(), greater<t>());
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define MINS(m, s) m.insert(mp(s, 1));
#define MFIN(m, s) m.find(s) != m.end()
#define mp make_pair
#define pb push_back
#define INF (1 << 29)
const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    reverse(all(s));
    string word[4] = {"dream", "dreamer", "erase", "eraser"};
    for(int i = 0; i < 4; i++) {
        reverse(all(word[i]));
    }

    for(int i = 0; i < s.length();) {
        bool flag = false;
        for(int j = 0; j < 4; j++) {
            if(s.substr(i, word[j].length()) == word[j]) {
                flag = true;
                i += word[j].length();
            }
        }
        if(!flag) {
            cout << "NO" << endl;
            exit(0);
        }
    }

    cout << "YES" << endl;

    return 0;
}