#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

int a[100005];

signed main()
{
    IO_OP;
    
    int n, l;
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    bool ok = false;
    int j;
    for (int i = 1; i < n; i++)
        if (a[i] + a[i+1] >= l) {
            ok = true;
            j = i;
        }
    if (!ok) return cout << "Impossible" << endl, 0;
    cout << "Possible" << endl;
    for (int i = 1; i < j; i++)
        cout << i << endl;
    for (int i = n - 1; i >= j; i--)
        cout << i << endl;
    

}

