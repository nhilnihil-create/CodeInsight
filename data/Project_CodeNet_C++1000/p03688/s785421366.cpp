#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;

const string YES = "Yes";
const string NO = "No";

int main(){
    ll n;
    cin >> n;
    map<ll, ll> a;
    REP(i, n){
        ll ai;
        cin >> ai;
        a[ai]++;
    }

    if(a.size() >= 3){
        cout << NO << endl;
    }else if(a.size() == 1){
        const ll a1 = a.begin()->first;
        if(a1 == n - 1 || a1 <= n / 2){
            cout << YES << endl;
        }else{
            cout << NO << endl;
        }
    }else{
        const ll a1 = a.begin()->first;
        const ll a2 = next(a.begin())->first;
        if(a1 + 1 != a2){
            cout << NO << endl;
        }else{
            const ll m2 = a[a2];
            const ll b2 = a2 - a[a1];
            if(m2 >= 2 && b2 > 0 && 2 * b2 <= m2){
                cout << YES << endl;
            }else{
                cout << NO << endl;
            }
        }
    }
    return 0;
}
