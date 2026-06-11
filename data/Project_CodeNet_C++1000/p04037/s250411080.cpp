#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    a.push_back(2000000000);
    sort(a.begin(), a.end(), greater<int>());
    bool win;
    bool before = true;
    bool after = true;
    int checked = 0;
    int left;
    int right;
    a.push_back(-1);
    for(int i = N; i >= 1; i--) {
        if(a[i] != a[i + 1]) {
            left = checked + 1;
            right = a[i];
            win = ((i+a[i]-1) % 2 == 0);
        }
        checked = right;
        //cerr << i << " " << a[i] << " " << win << " " << left << " " << right << endl;
        if(win == false) {
            if(left <= i && right >= i - 1) before = false;
            if(left <= i + 1 && right >= i) after = false;
        }
    }
    if(before || after) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
