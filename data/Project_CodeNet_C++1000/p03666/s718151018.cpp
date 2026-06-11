#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const string YES = "YES";
const string NO = "NO";

int main(){
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    REP(np, n - 1){
        const ll nn = n - 1 - np;
        const ll minv = np * c - nn * d;
        const ll maxv = np * d - nn * c;
        if(minv <= b - a && b - a <= maxv){
            cout << YES << endl;
            return 0;
        }
    }
    cout << NO << endl;
    return 0;
}
