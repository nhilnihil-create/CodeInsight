#include <bits/stdc++.h>
#define FOR(i,bg,ed) for(ll i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) for(ll i=1;i<=(n);i++)
#define MOD 1000000007
#define int long long
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1e9;

void bin(int lb, int ub)
{
    char ans;
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        cout << "? " << mid * 10 << endl;
        cin >> ans;
        if (ans == 'Y') {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    
    cout << "? " << lb * 10 << endl;
    cin >> ans;
    if (ans == 'Y') {
        cout << "! " << lb << endl;
    } else {
        cout << "! " << ub << endl; 
    }
    
    return;
}

signed main()
{
    char ans;
    
    cout << "? 1000000000" << endl;
    cin >> ans;
    
    if (ans == 'Y') {
        for (int i=1; i<=1000000000; i*=10) {
            cout << "? " << i * 2 << endl;
            cin >> ans;
            if (ans == 'Y') {
                cout << "! " << i << endl;
                return 0;
            }
        }
    } else {
        for (int i=100000000; i>=1; i/=10) {
            cout << "? " << i << endl;
            cin >> ans;
            if (ans == 'Y') {
                bin(i + 1, i * 10 - 1);
                return 0;
            }
        }
        cout << "! 1" << endl;
        return 0;
    }
}
