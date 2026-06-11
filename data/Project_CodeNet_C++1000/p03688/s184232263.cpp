#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    int a[N]; rep(i, N) cin >> a[i];
    sort(a, a + N);
    map<int, int>m;
    rep(i, N) {
        m[a[i]] = i;
    }
    if(m.size() > 2) {
        cout << "No" << endl;
        return 0;
    }
    if(m.size() == 1) {
        if(a[0] == N - 1 || N % a[0] == 0) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }else {
        int colorNum = m[a[0]] + 1;
        int nokori = a[N - 1] - colorNum;
        if(nokori <= 0) {
            cout << "No" << endl;
        }else if(a[0] + 1 == a[N - 1] && (N - m[a[0]] - 1) % nokori == 0) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
}
