#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
int n, q;

long long x[100005], l, y[100005][20];
vector<int> vec;

signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
        vec.pb(x[i]);
    }
    vec.pb(-1);
    sort(vec.begin(), vec.end());
    cin >> l;
    cin >> q;
    for(int i = 1; i <= n; i++){
        int it = upper_bound(vec.begin(), vec.end(), x[i] + l) - vec.begin() - 1;
        y[i][0] = it;
    }
    for(int i = 1; i <= 18; i++){
        for(int j = 1;j <= n; j++)
            y[j][i] = y[y[j][i - 1]][i - 1];
    }
    while(q--){
        int a, b, sum = 0;
        cin >> a >> b;
        if(a == b){
            cout << sum << "\n";
            continue;
        }
        if(b < a)
            swap(a, b);
        for(int i = 18; i >= 0; i--){
            if(y[a][i] < b){
                a = y[a][i];
                sum += (1 << i);
            }
        }
        sum++;
        cout << sum << "\n";
    }
}
