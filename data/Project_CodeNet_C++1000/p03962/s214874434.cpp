#include <bits/stdc++.h>
using namespace std;
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<ii> sii;
typedef set<int> si;
typedef priority_queue<int> pqi;
typedef priority_queue<ii> pqii;

const int INF = 1000000010;
const ll MOD = 1000000007;

int main() {FIN
    
    int a, b, c;
    cin >> a >> b >> c;
    si cl; cl.insert(a); cl.insert(b); cl.insert(c);
    cout << cl.size() << "\n";
    return 0;
}
